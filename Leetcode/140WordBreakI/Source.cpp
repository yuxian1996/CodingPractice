#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, vector<string>> sets;

void Break(string s, vector<string>& wordDict)
{
	if (s.size() == 0)
		return ;

	if (sets.find(s) != sets.end())
		return;

	vector<string> breaks;
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
			if (nextString == "")
			{
				breaks.push_back(s);
			}
			else
			{
				if (sets.find(nextString) == sets.end())
					Break(nextString, wordDict);
				vector<string>& nextBreaks = sets[nextString];
				for (int k = 0; k < nextBreaks.size(); ++k)
				{
					breaks.push_back(wordDict[i] + " " + nextBreaks[k]);
				}
			}
		}
	}
	sets[s] = breaks;

}

int main()
{
	vector<string> wordDict{ "aaaa", "aa", "a" };
	string s = "aaaaaaa";

	Break(s, wordDict);
	vector<string> res = sets[s];

	return 0;
	//return res;

}