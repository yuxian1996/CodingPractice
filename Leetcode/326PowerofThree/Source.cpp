int main()
{
	int n;

	if (n < 0)
		return false;
	if (n == 1)
		return true;

	while (n > 1 || n < -1)
	{
		if (n % 3 == 0)
		{
			n /= 3;
		}
		else
			return false;
	}

	return true;
}