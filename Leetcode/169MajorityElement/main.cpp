#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
	vector<int> nums{ 1 };
	
	unordered_map<int, int> map;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (map.find(nums[i]) == map.end())
			map[nums[i]] = 1;
		else if (++map[nums[i]] > nums.size() / 2)
			return nums[i];
	
	}
	return nums[nums.size() - 1];
}