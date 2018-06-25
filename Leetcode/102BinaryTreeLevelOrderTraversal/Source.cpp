#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int main()
{
	TreeNode* root;

	vector<vector<int>> res;
	if (root == nullptr)
		return res;

	vector<TreeNode* > queue;
	queue.push_back(root);


	while(true)
	{
		vector<TreeNode* > nextQueue;
		vector<int> values;
		for (int i = 0; i < queue.size(); ++i)
		{
			TreeNode* node = queue[i];
			if (node->left)
				nextQueue.push_back(node->left);
			if (node->right)
				nextQueue.push_back(node->right);

			values.push_back(node->val);
		}
		res.push_back(values);

		if (nextQueue.size() == 0)
			break;
		swap(queue, nextQueue);
	};

	return res;
}