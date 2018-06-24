#include <vector>
using namespace std;

void ConvertZero(int i, int j, vector<vector<char>>& board)
{
	board[i][j] = 1;
	if (i < board.size() -1 && board[i + 1][j] == 'O')
	{
		ConvertZero(i + 1, j, board);
	}
	
	if (i > 0 && board[i - 1][j] == 'O')
	{
		ConvertZero(i - 1, j, board);
	}

	if (j > 0 && board[i][j - 1] == 'O')
	{
		ConvertZero(i, j - 1, board);
	}
	if (j < board[0].size() - 1 && board[i][j + 1] == 'O')
	{
		ConvertZero(i, j + 1, board);
	}
}

int main()
{
	vector<vector<char>> board{
	{'X','X','X','X'},
	{'X','O','O','X'},
	{'X','X','O','X'},
	{'X','O','X','X'} };

	int rows = board.size(), columns = board[0].size();

	// up
	for (int i = 0; i < columns; ++i)
	{
		if (board[0][i] == 'O')
		{
			ConvertZero(0, i, board);
		}
		if (board[rows - 1][i] == 'O')
		{
			ConvertZero(rows - 1, i, board);
		}
	}

	for (int i = 0; i < rows; ++i)
	{
		if (board[i][0] == 'O')
		{
			ConvertZero(i, 0, board);
		}
		if (board[i][columns - 1] == 'O')
			ConvertZero(i, columns - 1, board);
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
			if (board[i][j] != 1)
				board[i][j] = 'X';
			else
				board[i][j] = 'O';
	}

	return 0;
}