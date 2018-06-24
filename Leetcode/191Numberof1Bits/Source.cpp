#include <cstdint>

int main()
{
	uint32_t n = 128;

	int res = 0;
	for (int i = 0; i < 32; ++i)
	{
		if (n & (1 << i))
			++res;
	}

	return res;
}