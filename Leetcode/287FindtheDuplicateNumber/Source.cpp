#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> nums{ 8,7,1,10,17,15,18,11,16,9,19,12,5,14,3,4,2,13,18,18 };

	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] != i + 1)
		{
			if (nums[i] == nums[nums[i] - 1])
				return nums[i];

			int tmp = nums[i];
			nums[i] = nums[tmp-1];
			nums[tmp-1] = tmp;
			--i;
		}
	}

}