#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
	vector<string> strs{ "eat", "tea", "tan", "ate", "nat", "bat" };

	// vector< unordered_map <char, int>> maps;
	 unordered_map<string, vector<string>> maps;
	 vector<vector<string>>  res;

	for (string str : strs)
	{
		string key = str;
		sort(key.begin(), key.end());
		maps[key].push_back(str);
	}
	
	for (auto val : maps)
	{
		res.push_back(val.second);
	}

	return 0;
}