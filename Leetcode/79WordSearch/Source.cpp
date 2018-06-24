#include <string>
#include <vector>
using namespace std;

bool FindNextAround(vector<vector<char>>& board, vector<vector<bool>>& isUsed, string& word, int index, int i , int j)
{
	if (index >= word.size())
		return true;

	// left
	if (i - 1 >= 0 && !isUsed[i - 1][j] && board[i - 1][j] == word[index] )
	{
		isUsed[i][j] = true;
		if (FindNextAround(board, isUsed, word, index + 1, i - 1, j))
			return true;
		else
			isUsed[i][j] = false;
	}
	// right
	if (i + 1 < board.size() && !isUsed[i + 1][j] && board[i + 1][j] == word[index])
	{
		isUsed[i][j] = true;
		if(FindNextAround(board, isUsed, word, index + 1, i + 1, j))
			return true;
		else isUsed[i][j] = false;
	}
	// up
	if (j + 1 < board[0].size() && !isUsed[i][j + 1] && board[i][j+1] == word[index])
	{
		isUsed[i][j] = true;
		if (FindNextAround(board, isUsed, word, index + 1, i, j + 1))
			return true;
		else
			isUsed[i][j] = false;
	}
	// down
	if (j - 1 >= 0 && !isUsed[i][j - 1] && board[i][j - 1] == word[index])
	{
		isUsed[i][j] = true;
		if (FindNextAround(board, isUsed, word, index + 1, i, j - 1))
			return true;
		else
			isUsed[i][j] = false;
	}

	return false;
}

int main()
{
	vector<vector<char>> board;
	string word;

	vector<vector<bool>> isUsed(board.size(), vector<bool>(board[0].size(), false));
	char first = word[0];
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[0].size(); ++j)
		{
			if (board[i][j] == first)
			{
				isUsed[i][j] = true;
				if (FindNextAround(board, isUsed, word, 1, i, j))
					return true;
				else
					isUsed[i][j] = false;
			}
		}
	}

	return false;


}