#include <vector>
using namespace std;

int main()
{
	vector<int> nums;

	int n = nums.size();
	int max = n* (n + 1) / 2;
	int total = 0;
	for (int num : nums)
	{
		total += num;
	}

	return max - total;
	
}