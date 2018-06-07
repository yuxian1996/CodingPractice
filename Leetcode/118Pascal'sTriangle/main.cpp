#include <vector>

using namespace std;

int main()
{
	int numRows = 5;
	vector<vector<int>> res;

	//if (numRows == 0)
		//return res;

	if (numRows >= 2)
	{
		res.push_back(vector<int>{1});
		res.push_back(vector<int>{1, 1});
	}
	else if (numRows == 1)
	{
		res.push_back(vector<int>{1});
	}

	for (int i = 2; i < numRows; ++i)
	{
		vector<int> row;
		row.push_back(1);
		for (int j = 1; j < i; ++j)
		{
			row.push_back(res[i - 1][j - 1] + res[i-1][j]);
		}
		row.push_back(1);
		res.push_back(row);
	}

	//return res;
}