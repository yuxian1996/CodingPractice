#include <vector>
#include <array>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
	vector<int> gas, cost;

	int start = 0, total = 0, tank = 0;
	for (int i = 0; i < gas.size(); ++i)
	{
		if ((tank = tank + gas[i] - cost[i]) < 0)
		{
			start = i + 1;
			total += tank;
			tank = 0;
		}
	}

	return (total + tank < 0) ? -1 : start;
}