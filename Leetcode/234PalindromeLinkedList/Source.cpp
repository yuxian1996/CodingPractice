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

	if (!head || !head->next)
		return true;

	ListNode* p1 = head, *p2 = head->next->next, *p3 = p1->next;
	ListNode* pRight = nullptr, *pLeft = nullptr;
	head->next = nullptr;

	while (p2)
	{
		if (p2->next)
			p2 = p2->next->next;
		else
		{
			break;
		}

		ListNode *p4 = p3->next;
		p3->next = p1;
		p1 = p3;
		p3 = p4;
	}

	if (!p2)
	{
		pRight = p3;
	}
	else
		pRight = p3->next;
	
	while (p1 && pRight)
	{
		if (p1->val != pRight->val)
			return false;
		p1 = p1->next;
		pRight = pRight->next;
	}

	return true;


}