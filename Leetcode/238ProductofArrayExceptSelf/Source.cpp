#include <vector>
using namespace std;

int main()
{
	vector<int> nums;

	int fromBegin = 1;
	int fromEnd = 1;
	int n = nums.size();
	vector<int> res(n, 1);

	for (int i = 0; i < n; ++i)
	{
		res[i] *= fromBegin;
		fromBegin *= nums[i];
		res[n - 1 - i] *= fromEnd;
		fromEnd *= nums[n - 1 - i];
	}

	return res;
}