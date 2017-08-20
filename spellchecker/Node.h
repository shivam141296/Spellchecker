#include <memory>
#include <unordered_map>
using namespace std;
static const int ALPHABETSIZE = 26;

struct Node {
    public:
	bool isEnd;
	int prefixCount;
	std::unordered_map<char, std::shared_ptr<Node>> children;
};
