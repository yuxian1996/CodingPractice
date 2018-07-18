#include <algorithm>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

 bool IsValid(TreeNode* node, int max, int min)
 {
	 
	 return !node || node->val <= max && node->val >= min && IsValid(node->left, node->val - 1, min) && IsValid(node->right, max, node->val + 1) 
		 && (!node->left || node->left->val < node->val) && (!node->right || node->right->val > node->val);
 }

 int main()
 {
	 TreeNode* root;
	 

	 return IsValid(root, INT_MAX , INT_MIN);
 }