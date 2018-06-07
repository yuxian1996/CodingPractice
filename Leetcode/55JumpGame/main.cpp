#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> nums{ 1,1,1,0};

	if (nums.size() == 1)
		return true;

	int maxReach = nums[0];
	for (int i = 1; i < nums.size() && i <= maxReach; ++i)
		maxReach = std::max(maxReach, i + nums[i]);

	if (maxReach >= nums.size())
		return true;

	return false;


}
