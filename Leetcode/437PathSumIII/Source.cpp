#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

int SumTree(TreeNode* node, int sum)
{
	if (!node)
		return 0;
	return Sum(node, sum) + SumTree(node->left, sum) + SumTree(node->right, sum);
}

int Sum(TreeNode* node, int num)
{
	if (!node)
		return 0;
	if (node->val == num)
	{
		return Sum(node->left, 0) + Sum(node->right, 0) + 1;
	}

	return Sum(node->left, num - node->val) + Sum(node->right, num - node->val);
}

int main()
{
	TreeNode* root;
	int sum;

	int res = 0;
	TreeNode* p = root;


	return SumTree(root, sum);

}