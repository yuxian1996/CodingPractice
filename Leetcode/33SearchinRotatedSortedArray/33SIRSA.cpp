#include <vector>
using namespace std;

int main()
{
	vector<int> nums = {4,5,6,7,0,1,2};
	int target = 3;

	int left = 0, right = nums.size() - 1;

	// binary search
	// find which side is sorted
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] > target)
		{
			if (nums[left] <= nums[mid])
			{
				if (nums[left] <= target)
					right = mid;
				else
					left = mid + 1;
			}
			else
			{
				right = mid;
			}
		}
		else if(nums[mid] < target)
		{
			if (nums[right] >= nums[mid])
			{
				if (nums[right] >= target)
					left = mid + 1;
				else
					right = mid;
			}
			else
			{
				left = mid + 1;
			}
		}
		else return mid;
	}

	if (nums[left] == target)
		return left;
	
	return -1;

}