#include <vector>
using namespace std;

int main()
{
	vector<int> nums;

	int i = 0, j = 0;

	for (int k = 0; k < nums.size(); ++k)
	{
		int value = nums[k];
		nums[k] = 2;
		if (value < 2)
		{
			nums[j++] = 1;
		}
		if (value == 0)
		{
			nums[i++] = 0;
		}
	}
}