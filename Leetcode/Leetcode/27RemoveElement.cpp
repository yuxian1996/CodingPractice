#include <vector>
using namespace std;

int main()
{
	vector<int> nums = { 1 };
	int val = 1;

	int i = 0, j = nums.size() - 1;

	while (i <= j)
	{
		if (nums[i] == val)
		{
			while (i < j)
			{
				if (nums[j] == val)
					j--;
				else
					break;
			}
			if (i != j)
			{
				nums[i++] = nums[j--];
			}
			else if (i == j)
			{
				break;
			}
		}
		else
			i++;
	}


	getchar();
	return i ;
}