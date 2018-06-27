#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string s = "anagram", t = "nagaram";

	int numS[26] = { 0 }, numT[26] = { 0 };

	for (auto val : s)
	{
		++numS[val - 'a'];
	}
	for (auto val : t)
	{
		++numT[val - 'a'];
	}

	for (int i = 0; i < 26; ++i)
		if (numT[i] != numS[i])
			return false;

	return true;
}