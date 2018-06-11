#include <string>
#include <vector>
using namespace std;

bool IsMatching(vector<vector<bool>>& sets, vector<vector<bool>> & dp, const string& s, int indexS, const string& p, int indexP)
{
	if (indexS < 0 || indexP < 0)
		return false;

	if (sets[indexS][indexP])
		return dp[indexS][indexP];

	if (IsMatching(sets, dp, s, indexS - 1, p, indexP - 1))
	{
		if (s[indexS - 1] == p[indexP - 1] || p[indexP - 1] == '*' || p[indexP - 1] == '?')
		{
			dp[indexS][indexP] = true;
		}
	}
	else if (IsMatching(sets, dp, s, indexS - 1, p, indexP))
	{
		if(indexP >= 1 && p[indexP-1] == '*')
			dp[indexS][indexP] = true;
	}
	else if (IsMatching(sets, dp, s, indexS, p, indexP - 1))
	{
		if(p[indexP - 1] == '*')
			dp[indexS][indexP] = true;
	}
	sets[indexS][indexP] = true;
	return dp[indexS][indexP];
}

int main()
{
	string s = "", p = "*";

	vector < vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
	vector<vector<bool>> sets(s.size() + 1, vector<bool>(p.size() + 1, false));
	sets[0][0] = true;
	dp[0][0] = true;
	
	IsMatching(sets, dp, s, s.size(), p, p.size());

	return dp[s.size()][p.size()];

}
