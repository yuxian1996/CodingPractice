struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

int main()
{
	ListNode* head;

	if (head == nullptr)
		return false;
	if (head->next == nullptr)
		return false;

	ListNode*p1 = head->next, *p2 = p1->next;

	if (!p2)
		return false;

	while (p1)
	{
		if (p2->next)
		{
			if (p2->next == p1 || p1 == p2)
				return true;
			p1 = p1->next;
			if (p2->next->next)
				p2 = p2->next->next;
			else
				return false;
		}
		else
			return false;
	}
	return false;
	
}