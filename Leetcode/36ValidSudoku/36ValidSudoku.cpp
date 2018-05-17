#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
	vector<vector<char>> board;
	unordered_set<char> rowSet, columnSet, sqaureSet;

	for (int i = 0; i < 9; i++)
	{
		// rows, columns
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] != '.')
			{
				if (rowSet.find(board[i][j]) == rowSet.end())
					rowSet.insert(board[i][j]);
				else
					return false;
			}
			if (board[j][i] != '.')
			{
				if (columnSet.find(board[j][i]) == columnSet.end())
					columnSet.insert(board[j][i]);
				else
					return false;
			}
		}
		rowSet.clear();
		columnSet.clear();

		// square
		for(int j = 0; j < 3; j ++)
			for (int k = 0; k < 3; k++)
			{
				char ch = board[i / 3 * 3 + j][i % 3 * 3 + k];
				if (ch != '.')
				{
					if (sqaureSet.find(ch) == sqaureSet.end())
						sqaureSet.insert(ch);
					else
						return false;
				}
			}

		sqaureSet.clear();
	}

	return true;
}