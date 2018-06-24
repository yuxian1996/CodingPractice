#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
	vector<int> nums{ 0,3,7,2,5,8,4,6,0,1};
	unordered_map<int, int> maps;
	int maxLength = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (maps.find(nums[i]) == maps.end())
		{
			maps[nums[i]] = 1;
			if (maps.find(nums[i]-1) != maps.end())
			{
				maps[nums[i]] += maps[nums[i]-1];
				if (maps.find(nums[i] + 1) != maps.end())
				{
					maps[nums[i]] += maps[nums[i] + 1];
					maps[nums[i] + maps[nums[i] + 1]] = maps[nums[i]];
					maps[nums[i] - maps[nums[i] - 1]] = maps[nums[i]];
				}
				else
				{
					maps[nums[i] - maps[nums[i] - 1]] = maps[nums[i]];
				}
			}
			else if (maps.find(nums[i]+1) != maps.end())
			{
				maps[nums[i]] += maps[nums[i]+1];
				maps[nums[i] + maps[nums[i] + 1]] = maps[nums[i]];
			}
			if (maps[nums[i]] > maxLength)
				maxLength = maps[nums[i]];
		}
	}

	return maxLength;

}