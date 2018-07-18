#include <unordered_map>
using namespace std;

class LRUCache {
public:
	struct List
	{
		int key;
		int val;
		List* next;
		List* last;
		List(int ikey, int value) : key(ikey), val(value), next(NULL) {};
	};

	unordered_map<int, List*> maps;
	List *head, *tail;
	int size = 0;
	int capacity = 0;

	LRUCache(int capacity) {
		//head = new List(0);
		this->capacity = capacity;
		size = 0;
	}

	int get(int key) {
		if (maps.find(key) == maps.end())
			return -1;

		auto node = maps[key];


		// this is not head
		if (head != node)
		{
			// this is tail
			if (tail == node)
			{
				tail = node->last;
			}
			node->last->next = node->next;
			if (node->next)
				node->next->last = node->last;
			node->next = head;
			head->last = node;
			head = node;
		}

		return node->val;
	}

	void put(int key, int value) {
		if (maps.find(key) != maps.end())
		{
			maps[key]->val = value;
			get(key);
			return;
		}
		if (size == 0 && capacity > 0)
		{
			head = new List(key, value);
			maps[key] = head;
			tail = head;
			++size;
			return;
		}

		if (size < capacity)
		{
			List* node = new List(key, value);
			maps[key] = node;
			node->next = head;
			head->last = node;
			head = node;
			++size;
		}
		else
		{
			maps.erase(tail->key);
			if (tail == head)
			{
				maps[key] = tail;
				tail->val = value;
				tail->key = key;
			}
			else
			{
				List* node = tail;
				maps[key] = node;
				tail = node->last;
				tail->next = nullptr;

				node->next = head;
				head->last = node;
				head = node;
				node->key = key;
				node->val = value;

			}

		}
	}
};

int main()
{
	int capacity = 3;
	LRUCache obj(capacity);
	int res;
	obj.put(1,1);
	obj.put(2,2);
	obj.put(3,3);
	obj.put(4,4);

	res = obj.get(4);
	res = obj.get(3);
	res = obj.get(2);
	res = obj.get(1);
	obj.put(5,5);
	res = obj.get(1);
	res = obj.get(2);
	res = obj.get(3);
	res = obj.get(4);
	res = obj.get(5);


	return 0;
}