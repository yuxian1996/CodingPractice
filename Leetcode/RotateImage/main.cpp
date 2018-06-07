#include <vector>
using namespace std;

int main()
{
	vector<vector<int>> matrix = {
		{5,1,9,11},
		{2,4,8,10},
		{13,3,6,7},
		{15,14,12,16}
	};

	size_t size = matrix.size();

	for (int i = 0; i < size / 2; ++i)
	{
		for (int j = i; j < size - 1 - i ; ++j)
		{
			int temp = matrix[i][j];
			matrix[i][j] = matrix[size -1 - j][i];
			matrix[size - 1 - j][i] = matrix[size - 1 - i][size - 1 - j];
			matrix[size - 1 - i][size - 1 - j] = matrix[j][size - 1 - i];
			matrix[j][size - 1 - i] = temp;
		}
	}

	return 0;
}