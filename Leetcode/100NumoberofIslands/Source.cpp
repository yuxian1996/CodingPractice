#include <vector>
using namespace std;

int number = 0;

void ScanIsland(vector<vector<char>>& grid, int i, int j, int lasti, int lastj, int firsti, int firstj);

void FindIsland(vector<vector<char>>& grid, int starti, int startj)
{
	for (int i = starti; i < grid.size(); ++i)
	{
		for (int j = startj; j < grid[0].size(); ++j)
			if (grid[i][j] == '1')
			{
				++number;
				ScanIsland(grid, i, j, -1, -1, i, j);
			}
	}
}

void ScanIsland(vector<vector<char>>& grid,int i , int j, int lasti, int lastj, int firsti, int firstj )
{
	if (i == firsti && j == firstj && lasti >= 0 && lastj >= 0)
	{
		grid[i][j] = 0;
		return;
	}

	grid[i][j] = 0;
	// right
	if (j < grid[0].size() - 1 && grid[i][j + 1] == '1')
	{
		ScanIsland(grid, i, j + 1, i, j, firsti, firstj);
	}
	
	// down
	if (i < grid.size() - 1 && grid[i + 1][j] == '1')
	{
		ScanIsland(grid, i + 1, j, i, j, firsti, firstj);
	}

	//up
	if (i > 0 && grid[i - 1][j] == '1')
	{
		ScanIsland(grid, i-1, j, i, j, firsti, firstj);
	}

	// left
	if(j > 0 && grid[i][j-1] == '1')
		ScanIsland(grid, i , j - 1, i, j, firsti, firstj);

}

int main()
{
	vector<vector<char>> grid
	{ {'1','1','1'},
	{'0','1','0'},
	{'1','1','1'} };

	FindIsland(grid, 0, 0);

	return number;
}