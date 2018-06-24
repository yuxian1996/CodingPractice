#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> nums{ 1,3,1,3,100 };
	
	if (nums.size() == 0)
		return 0;
	if (nums.size() == 1)
		return nums[0];
	if (nums.size() == 2)
		return max(nums[0], nums[1]);

	vector<int> res(nums.size(), 0);
	res[0] = nums[0];
	res[1] = max(nums[0], nums[1]);

	for (int i = 2; i < nums.size(); ++i)
		res[i] = max(res[i - 2] + nums[i], res[i - 1]);

	return res[res.size() - 1];
}