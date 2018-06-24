#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void Build(TreeNode* node, vector<int>& preorder, vector<int>& inorder, int& preStart, int& inStart)
{

	
}

int main()
{
	vector<int> preorder, inorder;

	if (preorder.size() == 0)
		return NULL;

	TreeNode* root = new TreeNode(0);
	int preStart = 0, inStart = 0;
	Build(root, preorder, inorder, preStart, inStart);
}