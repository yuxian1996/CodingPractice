#include <string>
#include <vector>
using namespace std;

int main()
{
	string s = "leetcode";

	vector<int> index(26, -1);
	for (int i = 0; i < s.size(); ++i)
	{
		if (index[s[i] - 'a'] == -1)
		{
			index[s[i] - 'a'] = i;
		}
		else
			index[s[i] - 'a'] = -2;
	}

	auto it = index.begin(), end = index.end();
	int min = INT_MAX;
	while (it != end)
	{
		if (*it != -1 && *it != -2 && *it < min)
			min = *it;
		++it;
	}

	return min == INT_MAX ? -1 : min;

}