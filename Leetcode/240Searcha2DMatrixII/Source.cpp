#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<vector<int>> matrix{ 
		{1,3,5,7,9},
		{2,4,6,8,10},
		{11,13,15,17,19},
		{12,14,16,18,20}
	};
	int target =13;

	if (matrix.size() == 0)
		return false;
	if (matrix[0].size() == 0)
		return false;

	int rows = matrix.size();
	int columns = matrix[0].size();
	int minNumber = min(rows, columns);
	for(int i = 0; i < minNumber; ++i)
	{
		if (matrix[i][i] == target)
			return true;
		else if(matrix[i][i] < target)
			continue;
		else
		{
			for (int k = i; k >= 0; --k)
				if (matrix[i][k] == target)
					return true;
				else if (matrix[i][k] < target)
					break;

			for (int k = i; k >= 0; --k)
				if (matrix[k][i] == target)
					return true;
				else if (matrix[k][i] < target)
					break;
		}
	}

	if (columns > minNumber)
	{
		for (int i = minNumber; i < columns; ++i)
		{
			
		}
	}

	return false;
}