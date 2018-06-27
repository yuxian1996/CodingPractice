#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

int main()
{
	ListNode* node;

	node->val = node->next->val;
	ListNode* nextNode = node->next;
	node->next = nextNode->next;
	delete nextNode;
}