#include <string>
#include <vector>
using namespace std;

int main()
{
	string s = "301";

	if (s[0] == '0')
		return 0;

	if (s.size() == 1)
		return 1;
	
	vector<int> dp(s.size(), 0);

	if (s[0] == '0')
	{
		dp[0] = 0;
		dp[1] = 0;
	}
	else
	{
		dp[0] = 1;

		if (s[0] == '1'|| (s[0] == '2' && s[1] <= '6'))
		{
			if (s[1] == '0')
				dp[1] = 1;
			else
				dp[1] = 2;
		}
		else if (s[1] == '0')
			dp[1] = 0;
		else
			dp[1] = 1;
	}

	for (int i = 2; i < s.size(); ++i)
	{
		if (s[i] == '0')
			dp[i] = 0;
		else
			dp[i] = dp[i - 1];
		if ((s[i - 1] == '1' && s[i] <= '9') || (s[i - 1] == '2' && s[i] <= '6'))
			dp[i] += dp[i - 2];
	}

	return dp[dp.size() - 1];
}