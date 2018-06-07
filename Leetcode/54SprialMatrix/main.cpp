#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<vector<int>> matrix{
		{1,2},
		{3,4},
		{5,6},
		{7,8}
	};

	vector<int> res;

	//if (matrix.size() == 0)
	//	return res;
	//if (matrix[0].size() == 0)
		//return res;

	//if (matrix.size() == 1)
	//{
	//	res = matrix[0];
	//	return res;
	//}

	//if (matrix[0].size() == 1)
	//{
	//	for (int i = 0; i < matrix.size(); ++i)
	//		res.push_back(matrix[i][0]);
	//	return res;
	//}

	int rows = matrix.size();
	int coloums = matrix[0].size();

	int minNum = std::min(rows, coloums);
	int num = 0;
	//if (minNum % 2 == 0)
	//	num = minNum / 2 + 1;
	//else
	//	num = minNum / 2;

	for (int i = 0; i < minNum / 2; ++i)
	{
		int numRow = coloums - i * 2 - 1;
		int numCol = rows - i * 2 - 1;
		// top
		for (int j = 0; j < numRow; ++j)
		{
			res.push_back(matrix[i][j + i]);
		}
		// right
		for (int j = 0; j < numCol; ++j)
		{
			res.push_back(matrix[j + i][coloums - 1- i]);
		}
		// bottom
		for (int j = 0; j < numRow; ++j)
		{
			res.push_back(matrix[rows - 1 - i][coloums - 1 - j - i]);
		}
		// left
		for (int j = 0; j < numCol; ++j)
		{
			res.push_back(matrix[rows - 1 - j - i][i]);
		}
	}

	if (minNum % 2 != 0)
	{
		if (minNum == coloums)
		{
			int half = coloums / 2;
			for (int i = half; i < rows - half; ++i)
				res.push_back(matrix[i][half]);
		}
		else
		{
			int half = rows / 2;
			for (int i = half; i < coloums - half; ++i)
				res.push_back(matrix[half][i]);
		}
	}

	//if (coloums == rows && coloums % 2 != 0)
	//	res.push_back(matrix[rows / 2][rows / 2]);
	
	//else if (abs(rows - coloums) % 2 == 1)
	//	res.pop_back();


	return 0;
}