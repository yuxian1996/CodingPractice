#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

// return the last node
void Merge(ListNode* head1, ListNode* head2, int size1, int size2, ListNode*& newHead)
{
	ListNode* res = NULL;
	int count1 = size1, count2 = size2;

	if (head1->val < head2->val)
	{
		res = head1;
		head1 = head1->next;
		--count1;
		newHead = res;
	}
	else
	{
		res = head2;
		head2 = head2->next;
		--count2;
		newHead = res;
	}

	while (count1 && count2)
	{
		ListNode* p;
		if (head1->val < head2->val)
		{
			res->next = head1;
			head1 = head1->next;
			res = res->next;
			--count1;
		}
		else
		{
			res->next = head2;
			head2 = head2->next;
			res = res->next;
			--count2;

		}

	}

	if (count1)
	{
		res->next = head1;
		while (count1)
		{
			res = res->next;
			--count1;
		}
		if(res)
			res->next = NULL;
	}
	else if (count2)
	{
		res->next = head2;
		while (count2)
		{
			res = res->next;
			--count2;
		}
		if(res)
			res->next = NULL;
	}
}

ListNode* Sort(ListNode* head, int size, ListNode*& newHead)
{
	if (size == 1)
	{
		newHead = head;
		return head->next;
	}

	if (size % 2 == 0)
	{
		int half = size / 2;
		ListNode* newHead1 = NULL, *newHead2 = NULL;
		ListNode* mid = Sort(head, half, newHead1);
		ListNode* lastNode = Sort(mid, half, newHead2);
		Merge(newHead1, newHead2, half, half, newHead);
		return 	lastNode;
	}
	else
	{
		int half = size / 2;
		ListNode* newHead1 = NULL, *newHead2 = NULL;
		ListNode* mid = Sort(head, half, newHead1);
		ListNode* lastNode = Sort(mid, half + 1, newHead2);
		Merge(newHead1, newHead2, half, half + 1, newHead);
		return lastNode;
	}
}

int main()
{
	ListNode* head;
	head = new ListNode(-1);
	ListNode* node = head;
	node->next = new ListNode(5);
	node = node->next;
	node->next = new ListNode(3);
	node = node->next;
	node->next = new ListNode(4);
	node = node->next;
	node->next = new ListNode(0);

	//if (!head)
		//return head;

	ListNode* p = head;
	int count = 0;
	while (p)
	{
		++count;
		p = p->next;
	}
	ListNode* newHead = nullptr;
	// Merge two lists
	Sort(head, count, newHead);
	return 0;
	//return head;
}