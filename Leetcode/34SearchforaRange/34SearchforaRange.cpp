#include <vector>
using namespace std;

int main()
{
	vector<int> nums;
	int target;
	vector<int> res = { -1, -1 };

	if (nums.size() == 0)
		return res;

	int left = 0, right = nums.size();
	int leftIndex = -1, rightIndex = -1;
	int mid = 0;

	// binary search twice
	while (left < right)
	{
		mid = (left + right) / 2;
		if (nums[mid] >= target)
			right = mid;
		else
			left = mid + 1;
	}

	if (left == nums.size() || nums[left] != target)
		return res;

	leftIndex = left;

	left = 0;
	right = nums.size();
	mid = 0;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (nums[mid] > target)
			right = mid;
		else
			left = mid + 1;
	}
	rightIndex = left - 1;

	res[0] = leftIndex;
	res[1] = rightIndex;
	
	return res;
}