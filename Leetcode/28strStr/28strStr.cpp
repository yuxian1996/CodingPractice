#include <vector>
#include <string>
using namespace std;

int main()
{
	string haystatck = "aaaa", needle = "bba";

	if (needle == "")
		return 0;

	size_t index =haystatck.find(needle);

	if (index == string::npos)
		return -1;
	return index;
}