#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
	vector<int> nums;

	unordered_set<int> sets;

	for (int i = 0; i < nums.size(); ++i)
	{
		if (sets.find(nums[i]) == sets.end())
			sets.insert(nums[i]);
		else
			return true;
	}

	return false;
}