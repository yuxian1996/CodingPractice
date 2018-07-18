#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compare(int x, int y)
{
	if (x == 0)
		return false;
	if (y == 0)
		return true;

	long long total1 = x, total2 = y;
	int tempx = x, tempy = y;
	while (tempx)
	{
		tempx /= 10;
		total2 *= 10;
	}

	while (tempy)
	{
		tempy /= 10;
		total1 *= 10;
	}

	if (total1 + y < total2 + x)
		return false;
	return true;
}
int main()
{
	vector<int> nums = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };


	string res = "";
	sort(nums.begin(), nums.end(), compare);
	int count = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] = 0)
			++count;
		res += to_string(nums[i]);
	}
	if (count == nums.size())
		return "0";

	return 0;
	//return res;

}