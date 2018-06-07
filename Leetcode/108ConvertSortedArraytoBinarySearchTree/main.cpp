#include <algorithm>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

void Convert(vector<int>& nums, int left, int right, TreeNode* node)
{
	int mid = (left + right) / 2;
	node->val = nums[mid];
	if (left < mid)
	{
		TreeNode* leftNode = new TreeNode(0);
		Convert(nums, left, mid, leftNode);
		node->left = leftNode;
	}
	else
		node->left = NULL;

	if (mid < right - 1)
	{
		TreeNode* rightNode = new TreeNode(0);
		Convert(nums, mid + 1, right, rightNode);
		node->right = rightNode;
	}
	else
		node->right = NULL;
}

int main()
{
	vector<int> nums{ -10, -3, 0, 5, 9 };

	if (nums.size() == 0)
		return NULL;

	TreeNode* root = new TreeNode(0);
	Convert(nums, 0, nums.size(), root);

	return 0;
}