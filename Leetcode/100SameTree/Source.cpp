#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

bool IsSame(TreeNode* p, TreeNode *q)
{
	if (p && q)
		return p->val == q->val && IsSame(p->left, q->left) && IsSame(p->right, q->right);

	if (q || p)
		return false;

	return true;
}

int main()
{
	TreeNode*p, *q;
	return IsSame(p, q);

}