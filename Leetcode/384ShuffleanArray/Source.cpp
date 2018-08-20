#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
	vector<int> original;

	Solution(vector<int> nums) {
		original = nums;
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return original;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> newVector = original;
		for (int i = 0; i < newVector.size(); i++)
		{
			int num = i + rand() % (newVector.size() - i);
			int temp = newVector[i];
			newVector[i] = newVector[num];
			newVector[num] = temp;
		}
		return newVector;
	}
};
