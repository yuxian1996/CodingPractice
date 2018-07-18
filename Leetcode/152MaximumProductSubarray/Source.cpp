#include <vector>
#include <array>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> nums = {2,3,-2,4};

	vector<int> minProducts(nums.size());
	vector<int> maxProducts(nums.size());
	minProducts[0] = nums[0];
	maxProducts[0] = nums[0];

	for (int i = 1; i < nums.size(); i++)
	{
		int minProduct = minProducts[i - 1] * nums[i];
		int maxProduct = maxProducts[i - 1] * nums[i];

		minProducts[i] = min({minProduct, maxProduct, nums[i]});
		maxProducts[i] = max({ minProduct, maxProduct, nums[i] });

	}
	auto res = max_element(maxProducts.begin(), maxProducts.end());
	return *res;
}
