#include <vector>
using namespace std;

int main()
{
	vector<vector<int>> board;

	int rows = board.size();
	int columns = board[0].size();

	// 0 : die, 1 : live, -1 : die to live, 2 : live to die
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			// top
			int neighbors = 0;
			if (i > 0)
			{

				if (j > 0)
					neighbors += board[i - 1][j - 1] >= 1 ? 1 : 0;

				neighbors += board[i - 1][j] >= 1 ? 1 : 0;

				if (j < columns - 1)
					neighbors += board[i - 1][j + 1] >= 1 ? 1 : 0;
			}

			// bottom
			if (i < rows - 1)
			{
				if (j > 0)
					neighbors += board[i + 1][j - 1] >= 1 ? 1 : 0;

				neighbors += board[i + 1][j] >= 1 ? 1 : 0;
				
				if (j < columns - 1)
					neighbors += board[i + 1][j + 1] >= 1 ? 1 : 0;
			}
			
			// left
			if (j > 0)
				neighbors += board[i][j - 1] >= 1 ? 1 : 0;
			
			// right
			if (j < columns - 1)
				neighbors += board[i][j + 1] >= 1 ? 1 : 0;

			if (board[i][j] && !(neighbors == 2 || neighbors == 3))
			{
				board[i][j] = 2;
			}
			else if (!board[i][j] && neighbors == 3)
			{
				board[i][j] = -1;
			}
		}
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			if (board[i][j] == -1)
				board[i][j] = 1;
			else if (board[i][j] == 2)
				board[i][j] = 0;
		}
	}
}