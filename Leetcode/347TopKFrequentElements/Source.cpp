#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

int main()
{
	vector<int> nums{ 1,1,1,2,2,3 };
	int k = 2;

	if (k == 0 || nums.size() == 0)
		return vector<int>();

	unordered_map<int, int> maps;
	priority_queue<pair<int, int>> queue;
	//vector<int> maxNumbers(k, 0);

	for (int i = 0; i < nums.size(); ++i)
	{
		++maps[nums[i]];
	}

	for (auto& value : maps)
	{
		queue.push({ value.second, value.first });
	}

	vector<int> res(k, 0);
	for (int i = 0; i < k; ++i)
	{
		res[i] = queue.top().second;
		queue.pop();
	}

	//return res;
	return 0;
}