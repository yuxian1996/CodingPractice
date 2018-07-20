#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <ctime>
using namespace std;

class RandomizedSet {
public:
	unordered_map<int, int> maps;
	vector<int> vectors;
	unsigned int size = 0;
	unsigned int capacity = 0;

	/** Initialize your data structure here. */
	RandomizedSet() {
		srand(time(nullptr));
	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (maps.find(val) != maps.end())
			return false;

		maps.insert({ val, size++ });
		if (size > capacity)
		{
			vectors.push_back(val);
			++capacity;
		}
		else
		{
			vectors[size - 1] = val;
		}
		return true;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (maps.find(val) == maps.end())
			return false;

		auto element = maps.find(val);
		vectors[element->second] = vectors[--size];
		maps[vectors[element->second]] = element->second;
		maps.erase(val);
		return true;
	}

	/** Get a random element from the set. */
	int getRandom() {
		int index = size * (float)rand() / (RAND_MAX + 1);
		return vectors[index];
	}
};


int main()
{
	RandomizedSet obj;
	bool param_1 = obj.insert(0);
	param_1 = obj.insert(1);
	param_1 = obj.insert(2);

	//param_1 = obj.remove(2);

	int param_2 = obj.getRandom();
	param_2 = obj.getRandom();
	param_2 = obj.getRandom();
	param_2 = obj.getRandom();
	param_2 = obj.getRandom();
	param_2 = obj.getRandom();
	param_2 = obj.getRandom();
	param_2 = obj.getRandom();
	param_2 = obj.getRandom();


	return 0;
}