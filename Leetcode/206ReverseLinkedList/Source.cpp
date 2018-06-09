#include <algorithm>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

int main()
{
	ListNode* head;
	
	if (!head)
		return head;

	ListNode* p1 = head, *p2 = head->next;
	head->next = NULL;

	while (p2)
	{
		ListNode* p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}

	return p1;
}