
int main()
{
	int n = 5;

	int res = 0;
	while (n > 0)
	{
		res += n / 5;
		n /= 5;
	}

	return res;
}