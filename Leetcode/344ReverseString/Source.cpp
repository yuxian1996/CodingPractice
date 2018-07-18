#include <string>
using namespace std;

int main()
{
	string s;

	string res(s.size(), 0);
	for (int i = s.size() - 1; i >= 0; --i)
	{
		res[s.size() - 1- i] = s[i];
	}
	return res;
}