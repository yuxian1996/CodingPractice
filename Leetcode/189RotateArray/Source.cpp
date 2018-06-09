#include <vector>
using namespace std;

int main()
{
	vector<int> nums{ 1,2,3,4,5,6 };
	int k = 4;

	if (k == 0 || k == nums.size() || nums.size() == 1)
		return 0 ;

	if (k != 1 && k / nums.size() != 0)
		k = k % nums.size();

	int firstIndex = 0;
	int index = 0;
	int count = 0;
	int temp1 = nums[index];

	while (count < nums.size())
	{
		int next = (index + k >= nums.size()) ? (index + k - nums.size()) : (index + k);
		int temp2 = nums[next];

		nums[next] = temp1;
		++count;
		if (next != firstIndex)
		{
			index = next;
			temp1 = temp2;
		}
		else
		{
			++firstIndex;
			index = firstIndex;
			temp1 = nums[index];
		}
	}

	return 0;
}