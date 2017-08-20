
#include "Node.h"
#include <string>
using namespace std;
class Trie {
    public:
	shared_ptr<Node> head;
    shared_ptr<Node> giveword(string prefix) ;
   // The first const means the function is returning a const T reference.
   //The second one says that the method is not changing the state of the object. I.e. the method does not change any member variables.
	shared_ptr<Node> atPrefix(const string& prefix) const;

	Trie();

	void insert(const string& word) const;
	bool search(const string& word) const;

	unsigned int wordsWithPrefix(const string& prefix) const;
};
