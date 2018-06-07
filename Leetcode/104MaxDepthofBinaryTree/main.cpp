#include <cstdlib>
#include <algorithm>
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

int FindDepth(TreeNode* node)
{
	if (node == NULL)
		return 0;

	return std::max(FindDepth(node->left), FindDepth(node->right)) + 1;
}

int main()
{
	TreeNode* root;

	return FindDepth(root);


}