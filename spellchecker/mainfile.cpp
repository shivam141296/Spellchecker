
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Trie.h"
using namespace std;
int main() {
	Trie trie;
	ifstream file;
	string word, input;

	file.open("list.txt");

	//Ask for input
	cout<<"enter the string\n";
	cin >> input;

	char lowInput = tolower(input[0]);

	auto beenHere = false;
	//Add every word to the trie.
	while (getline(file, word)) {
		char lowWord = tolower(word[0]);
		//if word's first character equals to input's, go on, else, dont add it onto the trie.
		if (lowWord == lowInput) {
			beenHere = true;
			trie.insert(word);
			//if a perfect match has been found, break out of the loop.
			if (word == input) break;
		}
		//If you've already been on the word's first character
		//, and it isn't the same as the input's you are done.
		if (beenHere && lowWord != lowInput) break;
	}

	auto errors = false;
	string x = "";
	for (const char& i : input) {
		x += i;
		if (trie.wordsWithPrefix(x) == 0) {
			errors = true;
			cout << x << "<" << input.substr(x.length());
			trie.giveword(x);
			break;
		}
	}
	if (!errors)
		cout << "There are no errors.";
}
