#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> nums = { 0,1,0,3,12 };

	int count = 0;

	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] != 0)
		{
			nums[count++] = nums[i];
		}
	}

	for (int i = nums.size() - 1; i >= count; --i)
		nums[i] = 0;
	
}