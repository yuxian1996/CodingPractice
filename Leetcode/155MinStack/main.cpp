#include <algorithm>

struct ListNode
{
	ListNode* next;
	ListNode* last;
	ListNode* pointer;
	int value;
	ListNode(int val, ListNode* iNext, ListNode* iLast, ListNode* iPoiner)
	{
		value = val;
		next = iNext;
		last = iLast;
		pointer = iPoiner;
	}
};

class MinStack
{
public:
	MinStack()
	{

		headList = new ListNode(0, NULL, NULL, NULL);
		headStack = new ListNode(0, NULL, NULL, NULL);
		tailStack = headStack;
	}

	void push(int x)
	{
		ListNode* newListNode = new ListNode(x, NULL, NULL, NULL);
		ListNode* newStackNode = new ListNode(x, NULL, NULL, NULL);

		newStackNode->pointer = newListNode;
		newListNode->pointer = newStackNode;

		// link stack node
		newStackNode->last = tailStack;
		tailStack->next = newStackNode;
		tailStack = newStackNode;

		// link list node
		if (!headList->next)
		{
			headList->next = newListNode;
			newListNode->last = headList;
		}
		else if (x < headList->next->value)
		{
			newListNode->next = headList->next;
			headList->next = newListNode;
			newListNode->last = headList;
		}
		else
		{
			delete newListNode;
			newStackNode->pointer = NULL;
		}
	}

	void pop()
	{
		ListNode* node = tailStack;

		if (node->pointer)
		{
			ListNode* pointer = node->pointer;
			pointer->last->next = pointer->next;
			delete pointer;
		}
		
		tailStack = node->last;
		tailStack->next = NULL;
		delete node;
	}

	int top()
	{
		if (tailStack)
			return tailStack->value;
		else 
			return 0;
	}

	int getMin()
	{
		if (headList->next)
			return headList->next->value;
	}

private: 
	ListNode* headList;
	ListNode* headStack, *tailStack;
};