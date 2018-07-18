#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

struct List
{
	TreeNode* node;
	List* parent;
	int depth;
};

void  Search(TreeNode* tree, List* parentList, TreeNode* p, TreeNode* q, List*& listP, List*& listQ)
{
	if (listP && listQ)
		return;

	if (tree->val == p->val)
	{
		listP = parentList;
	}
	
	if (tree->val == q->val)
	{
		listQ = parentList;
	}


	if (tree->left)
	{
		List* leftList = new List;
		leftList->depth = parentList->depth+1;
		leftList->node = tree->left;
		leftList->parent = parentList;
		Search(tree->left, leftList, p, q, listP, listQ);
		if (listP && listQ)
			return;
	}

	if (tree->right)
	{
		List* rightList = new List;
		rightList->depth = parentList->depth+1;
		rightList->node = tree->right;
		rightList->parent = parentList;
		Search(tree->right, rightList, p, q, listP, listQ);
		if (listP && listQ)
			return;
	}

	return;
}

int main()
{
	TreeNode* root, *p, *q;
	root = new TreeNode(3);
	p = new TreeNode(5);
	q = new TreeNode(1);
	root->left = p;
	root->right = q;
	
	List* rootList = new List;
	rootList->node = root;
	rootList->parent = NULL;
	rootList->depth = 0;

	List* listP = nullptr, *listQ = nullptr; 
	Search(root, rootList, p, q, listP, listQ);

	if (!listP || !listQ)
		return NULL; 

	if (listP->depth > listQ->depth)
	{
		while (listP->depth  != listQ->depth)
		{
			listP = listP->parent;
		}
	}
	else if (listP->depth < listQ->depth)
	{
		while (listP->depth != listQ->depth)
		{
			listQ = listQ->parent;
		}
	}

	while (listP->node->val != listQ->node->val)
	{
		listP = listP->parent;
		listQ = listQ->parent;
	}

	return listP->node->val;
}