#include <stdlib.h>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

bool IsSymmetric(TreeNode* tree1,TreeNode* tree2)
{
	if (tree1 == NULL && tree2 != NULL || tree1 != NULL && tree2 == NULL)
		return false;
	
	if (tree1 == NULL && tree2 == NULL)
		return true;

	return tree1->val == tree2->val && IsSymmetric(tree1->left, tree2->right) && IsSymmetric(tree1->right, tree2->left);

}

int main()
{
	TreeNode* root;

	if (root == NULL)
		return true;

	if (root->left == NULL && root->right == NULL)
		return true;
	
	if (root->left != NULL && root->right == NULL || root->left == NULL && root->right != NULL)
		return false;

	return IsSymmetric(root->left, root->right);
}