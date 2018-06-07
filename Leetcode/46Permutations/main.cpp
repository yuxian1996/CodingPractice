#include <vector>
using namespace std;

int main()
{
	vector<int> nums{ 1,2,3 };

	//vector<vector<int>> res;
	if (nums.size() == 0)
		return vector<vector<int>>();
	
	vector<vector<vector<int>>> dp;

	vector<vector<int>> first{ vector<int>{nums[0]} };
	dp.push_back(first);

	for (int i = 1; i < nums.size(); ++i)
	{
		vector<vector<int>> newDp;
		for (int j = 0; j < dp[i - 1].size(); j++)
		{
			int size = dp[i - 1][j].size();
			for (int k = 0; k <= size; k++)
			{
				vector<int> vector1 = dp[i - 1][j];
				vector1.insert(vector1.begin() + k, nums[i]);
				newDp.push_back(vector1);
			}
		}

		dp.push_back(newDp);
	}

	return 0;
	//return dp[nums.size() - 1];

}