#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

void Invert(TreeNode* node)
{
	if (!node)
		return;

	TreeNode* tmp = node->left;
	node->left = node->right;
	node->right = tmp;
	Invert(node->left);
	Invert(node->right);
}

int main()
{
	TreeNode* root;
	Invert(root);
	return root;

}