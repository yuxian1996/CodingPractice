#include <algorithm>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
	
};

void Connet(TreeLinkNode* node, TreeLinkNode* parent)
{
	if (!node)
		return;

	if (!parent)
	{
		node->next = NULL;
		Connet(node->left, node);
	}
	else
	{
		node->next = parent->right;
		parent = parent->next;
		TreeLinkNode* first = node;
		node = node->next;
		while (parent)
		{
			node->next = parent->left;
			node->next->next = parent->right;
			parent = parent->next;
			node = node->next->next;
		}

		Connet(first->left, first);
	}
}

int main()
{
	TreeLinkNode* root;

	Connet(root, NULL);
}
