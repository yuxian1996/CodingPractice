#include <string>
#include <stack>
#include <algorithm>
using namespace std;

void Calculator(stack<int>& operands, stack<char>& operators)
{
	int right = operands.top();
	operands.pop();
	int left = operands.top();
	operands.pop();
	char op = operators.top();
	operators.pop();
	switch (op)
	{
	case '+':
		operands.push(left + right);
		break;
	case '-':
		operands.push(left - right);
		break;
	case '*':
		operands.push(left * right);
		break;
	case '/':
		operands.push(left / right);
		break;
	default:
		break;
	}
}

int main()
{
	string s = "1*2-3/4+5*6-7*8+9/10";

	stack<int> operands;
	stack<char> operators;

	size_t lastPos = 0;
	size_t pos = s.find_first_of("+-*/", 0);
		
	while(true)
	{
		if (pos == string::npos)
		{
			int number = stoi(string(s.begin() + lastPos, s.end()));
			operands.push(number);
			break;
		}

		int number = stoi(string(s.begin() + lastPos, s.begin() + pos));
		operands.push(number);

		while (true)
		{
			if (operators.size() == 0 || operands.size() == 1)
			{
				operators.push(s[pos]);
				break;
			}
			else if ((s[pos] == '*' || s[pos] == '/') && (operators.top() == '+' || operators.top() == '-'))
			{
				operators.push(s[pos]);
				break;
			}
			else
			{
				Calculator(operands, operators);
			}

		}

		lastPos = pos + 1;
		pos = s.find_first_of("+-*/", lastPos);
	} 

	while (operands.size() >= 2)
	{
		Calculator(operands, operators);
	}

	return operands.top();
}