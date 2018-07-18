#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
	vector<string> tokens = { "4", "13", "5", "/", "+" };

	if (tokens.size() == 0)
		return 0;
	if(tokens.size() == 1)
		return atoi(tokens[0].c_str());

	stack<int> stack;
	stack.push(atoi(tokens[0].c_str()));
	stack.push(atoi(tokens[1].c_str()));
	int left = 0, right = 0;
	int index = 2;

	while (index < tokens.size())
	{
		if (tokens[index] == "+")
		{
			right = stack.top();
			stack.pop();
			left = stack.top();
			stack.pop();
			stack.push(left + right);
		}
		else if (tokens[index] == "-")
		{
			right = stack.top();
			stack.pop();
			left = stack.top();
			stack.pop();
			stack.push(left - right);
		}
		else if (tokens[index] == "*")
		{
			right = stack.top();
			stack.pop();
			left = stack.top();
			stack.pop();
			stack.push(left * right);
		}
		else if (tokens[index] == "/")
		{
			right = stack.top();
			stack.pop();
			left = stack.top();
			stack.pop();
			stack.push(left / right);
		}
		else
			stack.push(atoi(tokens[index].c_str()));

		++index;
	}

	return stack.top();

}