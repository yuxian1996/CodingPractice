#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
	vector<int> nums1{ 1,2,2,1 }, nums2{ 2,2 };

	vector<int> res;
	unordered_map<int, int> maps;
	auto it = nums1.begin();
	while (it != nums1.end())
	{
		if (maps.find(*it) == maps.end())
			maps[*it] = 1;
		else
			++maps[*it];
		++it;
	}
	
	it = nums2.begin();
	while (it != nums2.end())
	{
		if (maps.find(*it) != maps.end() && maps[*it])
		{
			res.push_back(*it);
			--maps[*it];
		}
		
		++it;
	}

	return 0;

}