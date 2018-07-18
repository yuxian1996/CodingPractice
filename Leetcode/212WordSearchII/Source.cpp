#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool FindLetter(vector<vector<char>>& board, string& word, int index, int i, int j)
{
	int rows = board.size();
	int columns = board[0].size();
	if (i < 0 || i >= rows || j < 0 || j >= columns)
		return false;

	if (index == word.size() - 1)
	{
		if (board[i][j] == word[index])
			return true;
		else
			return false;
	}


	if (board[i][j] == word[index])
	{
		char tmp = board[i][j];
		board[i][j] = 0;
		// search next letter
		if (i > 0 && FindLetter(board, word, index + 1, i - 1, j) || i < rows - 1 && FindLetter(board, word, index + 1, i + 1, j) ||
			j > 0 && FindLetter(board, word, index + 1, i, j - 1) || j < columns - 1 && FindLetter(board, word, index + 1, i, j + 1))
		{
			return true;
		}
		board[i][j] = tmp;
		return false;

	}
	else
		return false;

}

bool Find(vector<vector<char>>& board, string& word)
{
	vector<vector<char>> tmpBoard = board;

	int rows = tmpBoard.size();
	int columns = tmpBoard[0].size();
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			if (tmpBoard[i][j] == word[0])
			{
				if (FindLetter(tmpBoard, word, 0, i, j))
					return true;
				else
					tmpBoard = board;
			}
		}
	}

	return false;
}

int main()
{
	vector<vector<char>> board{
		{'o','a','a','n'},
		{'e','t','a','e'},
		{'i','h','k','r'},
		{'i','f','l','v'}
	};
	vector<string> words{ "oath","pea","eat","rain" };
	sort(words.begin(), words.end());

	vector<string> res;
	if (words.size() > 0)
		if (Find(board, words[0]))
			res.push_back(words[0]);

	for (int i = 1; i < words.size(); ++i)
	{
		if (words[i] != words[i-1] && Find(board, words[i]))
			res.push_back(words[i]);
	}
		

	return 0;

}