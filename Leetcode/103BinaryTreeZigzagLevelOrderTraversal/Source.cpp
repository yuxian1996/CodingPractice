#include <vector>
#include <algorithm>
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
	if (!root)
		return res;

	vector<TreeNode*> nodes(1,root);
	bool isLeft = true;

	while (nodes.size() != 0)
	{
		vector<TreeNode*> nextNodes;
		vector<int> result(nodes.size(), 0);
		for (int i = nodes.size() - 1; i >= 0; --i)
		{
			result[result.size() - 1 - i] = nodes[i]->val;
			if (isLeft)
			{
				if(nodes[i]->left)
					nextNodes.push_back(nodes[i]->left);
				if(nodes[i]->right)
					nextNodes.push_back(nodes[i]->right);
			}
			else
			{
				if(nodes[i]->right)
					nextNodes.push_back(nodes[i]->right);
				if(nodes[i]->left)
					nextNodes.push_back(nodes[i]->left);
			}
		}
		res.push_back(result);
		nodes.swap(nextNodes);
		isLeft = !isLeft;
	}

	return res;
}