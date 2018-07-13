#include <vector>
#include <string>
using namespace std;

class Trie {
public:

	struct PrefixNode
	{
		char val;
		PrefixNode** nodes;
		int count;
		PrefixNode(char value) : val(value) { nodes = new PrefixNode*; count = 0; };
	};

	PrefixNode* head;
	/** Initialize your data structure here. */
	Trie() {
		head = new PrefixNode(0);
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {

	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		PrefixNode* parent = head;
		for (int i = 0; i < prefix.size(); ++i)
		{
			for (int j = 0; j < parent->count; ++j)
			{
				if (parent->nodes[j]->val == prefix[i])
				{
					parent = parent->nodes[j];
					break;
				}
			}
		}
	}
};

int main()
{
	Trie obj();
	//obj.insert(word);
	//bool param_2 = obj.search(word);
	//bool param_3 = obj.startsWith(prefix);
}