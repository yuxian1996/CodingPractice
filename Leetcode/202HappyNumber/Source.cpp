#include <algorithm>
#include <unordered_set>
using namespace std;

int main()
{
	int n = 19;

	unordered_set<int> set;

	set.insert(n);
	
	while (true)
	{
		int res = 0;
		while (n)
		{
			res += pow((n % 10), 2);
			n /= 10;
		}
		if (res == 1)
			return true;
		
		if (set.find(res) != set.end())
			return false;
		else
		{
			set.insert(res);
			n = res;
		}
	}
}