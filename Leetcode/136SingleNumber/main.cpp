#include <vector>
using namespace std;

int main()
{
	vector<int> nums;

	if (nums.size() == 1)
		return nums[0];

	int res = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		res ^= nums[i];
	}
	return res;
}