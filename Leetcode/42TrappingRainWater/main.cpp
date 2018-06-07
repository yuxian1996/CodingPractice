#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> height{ 0,1,0,2,1,0,1,3,2,1,2,1 };

	if (height.size() == 0 || height.size() == 1 || height.size() == 2)
		return 0;

	int left = 0, right = height.size() - 1;
	int leftHeight = height[0], rightHeight = height[right];
	int store = 0;
	bool isLeft = true;

	while (left < right)
	{
		if (isLeft)
		{

		}
	}

	
}
