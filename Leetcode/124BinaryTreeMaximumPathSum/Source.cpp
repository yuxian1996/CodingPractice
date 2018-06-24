#include <vector>
#include <algorithm>
using namespace std;

 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

 int maxSum = INT_MIN;

 int MaxPathSum(TreeNode* node)
 {
	 int leftMax = 0, rightMax = 0;
	 if (node->left)
		 leftMax = MaxPathSum(node->left);
	 if (node->right)
		 rightMax = MaxPathSum(node->right);

	 int localMax = leftMax > 0 ? (leftMax + (rightMax > 0 ? rightMax : 0) + node->val) : ((rightMax > 0 ? rightMax : 0 ) + node->val);
	 if (localMax > maxSum)
		 maxSum = localMax;

	 if (leftMax > 0 && leftMax > rightMax)
		 return leftMax + node->val;
	 
	 if (rightMax > 0 && rightMax > leftMax)
		 return rightMax + node->val;

	 return node->val;
 }

 int main()
 {
	 TreeNode* root;

	 MaxPathSum(root);
	 return maxSum;

 }