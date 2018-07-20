#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, bool> sets;

bool CanBreak(string s, vector<string>& wordDict)
{
	if (s.size() == 0)
		return true;

	if (sets.find(s) != sets.end())
		return sets[s];

	string nextString;
	bool find = false;
	for (int i = 0; i < wordDict.size(); ++i)
	{
		int j = 0;
		for (; j < wordDict[i].size(); j++)
		{
			if (s[j] != wordDict[i][j])
				break;
		}
		if (j >= wordDict[i].size())
		{
			nextString = string(s.begin() + wordDict[i].size(), s.end());
			if (CanBreak(nextString, wordDict))
			{
				sets[s] = true;
				return true;
			}
		}
	}
	
	sets[s] = false;
	return false;
}

int main()
{
	vector<string> wordDict{ "car", "ca", "rs" };
	string s = "cars";

	bool res = CanBreak(s, wordDict);
	return res;

}