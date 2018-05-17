#include <vector>
#include <algorithm>
using namespace std;

int maxSubArray(vector<int>& nums, int left, int right, int& subLeft, int& subRight, bool isLeft)
{
	if (left == right - 1)
	{
		subLeft = left;
		subRight = right;
		return nums[left];
	}

	int Lleft, Lright, Lmax, Rleft, Rright, Rmax;
	int mid = (left + right) / 2;

	Lmax = maxSubArray(nums, left, mid, Lleft, Lright, true);
	Rmax = maxSubArray(nums, mid, right, Rleft, Rright, false);

	// todo
	int max = Lmax;
	for (int i = Lright; i < Rleft; i++)
	{
		max += nums[i];
	}
	max += Rmax;
	//...

	if (max >= Lmax && max >= Rmax)
	{
		subLeft = Lleft;
		subRight = Rright;
		return max;
	}
	else if (Lmax > Rmax)
	{
		subLeft = Lleft;
		subRight = Lright;
		return Lmax;
	}
	else if(Rmax > Lmax)
	{
		subLeft = Rleft;
		subRight = Rright;
		return Rmax;
	}
	else if (isLeft)
	{
		subLeft = Rleft;
		subRight = Rright;
		return Rmax;
	}
	else
	{
		subLeft = Lleft;
		subRight = Lright;
		return Lmax;

	}
}

int main()
{
	vector<int> nums = {-2, 1, -3, 4, -1,2, 1, -5, 4};

	//int left, right;
	//int res = maxSubArray(nums, 0, nums.size(), left, right, true);
	//return res;

	int* dp = new int[nums.size()];
	dp[0] = nums[0];

	int max = dp[0];

	for (int i = 1; i < nums.size(); i++)
	{
		if (dp[i-1] > 0)
			dp[i] = dp[i - 1] + nums[i];
		else
			dp[i] = nums[i];

		max = std::max(max, dp[i]);
	}
	
	return max;
}