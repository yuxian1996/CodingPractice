#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n = 13;

	vector<int> dp(n + 1, 0);
	dp[0] = 0;

	for (int i = 1; i <= n; ++i)
	{
		//int tmp = i;
		int min = INT_MAX;
		int index = -1;
		for (int j = 1;; ++j)
		{
			int tmp = i - j*j;
			if (tmp < 0)
				break;

			if (dp[tmp] < min)
			{
				index = tmp;
				min = dp[tmp];
			}
		}

		dp[i] = dp[index] + 1;
	}

	return dp[dp.size() - 1];
}