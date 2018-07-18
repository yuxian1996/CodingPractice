
int main()
{
	int a = -1, b = 1;

	int res = 0;
	bool flag = 0;
	for (int i = 0; i < 32; ++i)
	{
		bool bita, bitb;
		bita = a & (1 << i);
		bitb = b& (1 << i);
		if (bita&bitb&flag)
		{
			flag = true;
			res |= 1 << i;
		}
		else if (bita&bitb & !flag || bita & !bitb&flag || !bita&bitb&flag)
			flag = true;
		else if (bita & !bitb & !flag || !bita&bitb & !flag || !bita & !bitb&flag)
		{
			res |= 1 << i;
			flag = false;
		}
		else
			flag = false;
	}
	
	return res;
}