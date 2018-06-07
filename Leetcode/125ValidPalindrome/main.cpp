#include <string>
#include <cctype>
using namespace std;

int main()
{
	string s = "0P";

	if (s.size() == 0 || s.size() == 1)
		return true;

	int left = 0, right = s.size() - 1;
	while (left < right)
	{
		if (!isalnum(s[left]))
		{
			++left;
			continue;
		}
		if (!isalnum(s[right]))
		{
			--right;
			continue;
		}

		if (tolower(s[left]) != tolower(s[right]))
			return false;

		++left;
		--right;
	}

	return true;
}