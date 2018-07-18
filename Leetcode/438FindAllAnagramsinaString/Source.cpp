#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
	string s = "cbaebabacd", p = "abc";

	int numbers[26] = { 0 };
	int numbers2[26] = { 0 };
	vector<int> res;

	for (int i = 0; i < p.size(); ++i)
	{
		++numbers[p[i] - '0'];
	}

	for (int i = 0; i < s.size(); ++i)
	{
		if()
	}

	//return res;
	return 0;
}