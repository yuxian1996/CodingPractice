#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void TraverseTree(vector<int>& res, TreeNode* node)
{
	if (node == nullptr)
		return;

	TraverseTree(res, node->left);
	res.push_back(node->val);
	TraverseTree(res, node->right);
}

int main()
{
	TreeNode* root;

	vector<int> res;
	TraverseTree(res, root);
	return res;
	
}