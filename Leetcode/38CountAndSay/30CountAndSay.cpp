#include <vector>
#include <string>
using namespace std;
void Count(string& str)
{
	char pre = str[0];
	int count = 1;
	string res;
	for (int i = 1; i < str.size(); i++)
	{
		if (str[i] == pre)
		{
			count++;
			continue;
		}
		else
		{
			res.append(to_string(count) + pre);
			pre = str[i];
			count = 1;
		}
	}

	res.append(to_string(count) + pre);
	
	str = res;
}

int main()
{
	int n = 5;
	string start = "1";
	//if (n == 1)
		//return start;

	for (int i = 0; i < n - 1; i++)
		Count(start);
	return 0;
}