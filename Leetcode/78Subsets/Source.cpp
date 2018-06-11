#include <vector>
using namespace std;

int main()
{
	vector<int> nums = { 1,2,3 };

	vector < vector<int>> last;
	last.push_back(vector<int>());

	for (int i = 0; i < nums.size(); ++i)
	{
		vector<vector<int>> res;
		for (int j = 0; j < last.size(); ++j)
		{
			res.push_back(last[j]);
			vector<int> newVector = last[j];
			newVector.push_back(nums[i]);
			res.push_back(newVector);
		}
		last.swap(res);
	}

	return last;
}