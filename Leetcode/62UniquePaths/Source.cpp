#include <vector>
using namespace std;

int main()
{
	int m = 3, n = 2;

	vector<vector<int>> dp;
	
	dp.push_back(vector<int>(n, 1));

	for (int i = 1; i < m; ++i)
	{
		dp.push_back(vector<int>(n, 1));
		dp[i][0] = 1;

		for (int j = 1; j < n; ++j)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	return dp[m][n];
}