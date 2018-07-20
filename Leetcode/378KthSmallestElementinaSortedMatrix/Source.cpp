#include <vector>
#include <cmath>
using namespace std;

int main()
{
	vector<vector<int>> matrix{
		{1,3,5},
		{6,7,12},
		{11,14,14}
	};
	int k = 3;

	double sq = sqrt(k);
	int floor = floorf(sq);
	int ceil = ceilf(sq);

	int index;
	if (floor * floor == k)
	{
		//index = floor - 1;
		return matrix[floor-1][floor-1];
	}
	else if (ceil * ceil == k)
		return matrix[ceil-1][ceil-1];
	else
		index = floor;

	int count = k - floor * floor;
	int rows = matrix.size();
	int columns = matrix[0].size();

	int num = 0;
	int i = 0, j = 0;
	bool isRow = true;
	while (num < count)
	{
		if (matrix[i][index] < matrix[index][j])
		{
			++i;
			isRow = true;
		}
		else
		{
			++j;
			isRow = false;
		}
		++num;

	}

	return isRow ? matrix[i - 1][index] : matrix[index][j-1];
}