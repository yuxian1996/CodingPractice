#include <cstdint>

int main()
{
	uint32_t n = 43261596;
	uint32_t res = 0;
	for (int i = 31; i >=0; --i)
	{
		if (n & 1 << i)
			res |= 0x80000000 >> i;
	}
	return res;
}