#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<int, vector<vector<string>>> maps;

void Partition(string& s, int left, int right)
{
	if (left == right)
		return;

	if (maps.find(left*10 + right) != maps.end())
		return;

	vector<vector<string>> partition;
	bool isPalidorome = false;

	int i = left, j = right - 1;
	while (i < j)
	{
		if (s[i] != s[j])
			break;
		++i, --j;
	}

	if (i >= j)
	{
		partition.push_back(vector<string>(1, string(s.begin() + left, s.begin() + right)));
		isPalidorome = true;
	}

	//int max = isPalidorome ? (right + left) / 2 + 1 : right;
	int max = right;
	for (int i = left + 1; i < max ; ++i)
	{
		int index = left * 10 + i;
		if (maps.find(index) == maps.end())
		{
			Partition(s, left, i);
		}
		
		vector<vector<string>>& leftPartition = maps[left * 10 + i];
		//partition.insert(partition.end(), leftPartition.begin(), leftPartition.end());

		if (maps.find(i * 10 + right) == maps.end())
		{
			Partition(s, i, right);
		}

		vector<vector<string>>& rightPartition = maps[i * 10 + right];
		//partition.insert(partition.end(), rightPartition.begin(), rightPartition.end());
		auto leftBegin = leftPartition.begin();
		auto rightBegin = rightPartition.begin();
		while (leftBegin < leftPartition.end() )
		{
			if (leftBegin->size() != 0)
			{
				vector<string> strings = *leftBegin;
				while (rightBegin < rightPartition.end())
				{
					if (rightBegin->size() != 0)
					{
						strings.insert(strings.end(), rightBegin->begin(), rightBegin->end());
						partition.push_back(strings);
					}
					++rightBegin;
				}
			}
				++leftBegin;
		}
	}
	
	maps[left * 10 + right] = partition;

}


int main()
{
	string s = "fff";
	
	vector<vector<string>> res;

	Partition(s, 0, s.size());
	return 0;

	//return maps[s.size() + 1];
}