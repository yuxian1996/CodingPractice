#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
	
};


int main()
{
	RandomListNode* head;

	//if (!head)
	//	return NULL;
	
	head = new RandomListNode(1);
	head->next = new RandomListNode(2);
	head->random = head->next;
	head->next->random = head->next;

	RandomListNode* p = head->next, *random = head->random;
	unordered_map<int, RandomListNode*> maps;
	maps[head->label] = new RandomListNode(head->label);
	RandomListNode* res = maps[head->label];

	while (p)
	{
		if (maps.find(p->label) == maps.end())
		{
			RandomListNode* node = new RandomListNode(p->label);
			//head->next = node;
			maps[head->label]->next = node;
			maps[p->label] = node;
		}
		else
		{
			maps[head->label]->next = maps[p->label];
		}

		if (random)
		{
			if (maps.find(random->label) == maps.end())
			{
				RandomListNode* node = new RandomListNode(random->label);
				//head->random = node;
				maps[head->label]->random = node;
				maps[random->label] = node;
			}
			else
			{
				maps[head->label]->random = maps[random->label];
			}
		}

		head = head->next;
		p = head->next;
		random = head->random;
	}

	if (random)
	{
		maps[head->label]->random = maps[random->label];
	}

	//return res;
}