#include "Trie.h"
#include<iostream>
#include<string.h>
using namespace std;
Trie::Trie() : head(make_shared<Node>()){
	head->isEnd = false;
	head->prefixCount = 0;
}

void allword(shared_ptr<Node> next,string prefix)
{
    if(next->isEnd ==true)
            cout<<"\ncorrect word:"<<prefix;
    int i;
     for( i=0;i<26;i++)
    {

        auto next1 = next->children[i];
        if(!next1)
            continue;
        else
        {
            allword(next1,prefix+(char)(97+i));
        }
    }

}


shared_ptr<Node> Trie::giveword(string prefix){
	auto current = head;
	for (const char& c : prefix) {
		auto letter = c - 'a';
		auto next = current->children[letter];
		if (!next) break;
		current = next;
	}
    allword(current,prefix.substr(0,prefix.length()-1));
	return current;
}



shared_ptr<Node> Trie::atPrefix(const std::string& prefix) const{
	auto current = head;
	for (const char& c : prefix) {
		auto letter = c - 'a';
		auto next = current->children[letter];
		if (!next) return nullptr;
		current = next;
	}
	return current;
}

void Trie::insert(const string& word) const{
	auto current = head;
	for (const char& c : word) {
		auto letter = c - 'a';
		if(letter<0)break;
		auto& next = current->children[letter];
		if (!next) next = make_shared<Node>();
		current->children[letter]->prefixCount++;
		current = current->children[letter];
	}

	current->isEnd = true;
}

bool Trie::search(const string& word) const{
	auto node = atPrefix(word);
	return node && node->isEnd;
}

unsigned int Trie::wordsWithPrefix(const string& prefix) const {
	auto node = atPrefix(prefix);
	return node ? node->prefixCount : 0;
}
