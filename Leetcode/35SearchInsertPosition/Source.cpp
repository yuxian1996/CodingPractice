#include <vector>
using namespace std;

int main()
{
	vector<int> nums;
	int target;

	if (nums.size() == 0 || nums[0] >= target)
		return 0;

	for (int i = 0; i < nums.size() - 1; ++i)
		if (nums[i] < target && nums[i + 1] >= target)
			return i + 1;

	return nums.size();
}