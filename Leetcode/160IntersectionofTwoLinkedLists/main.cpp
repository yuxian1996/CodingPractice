#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* FindNode(ListNode* nodeA, ListNode* nodeB, int countA, int countB)
{
	int diff = std::abs(countA - countB);
	if (countA > countB)
	{
		for (int i = 0; i < diff; ++i)
			nodeA = nodeA->next;
	}
	else
	{
		for (int i = 0; i < diff; ++i)
			nodeB = nodeB->next;
	}
	
	while (nodeA != nodeB)
	{
		nodeA = nodeA->next;
		nodeB = nodeB->next;
	}

	return nodeA;
}

int main()
{
	ListNode* headA, *headB;

	ListNode* a, *b;
	while (a != b)
	{
		a = a ? a->next : headB;
		b = b ? b->next : headA;
	}

	return a;
}