int main()
{
	int x = 2147395599;

	long long r = 0;
	long long left = 1, right = x;
	while (true)
	{
		r = (left + right) / 2;

		if (r*r <= x && (r + 1)*(r + 1) > x)
			return r;
		
		if (r*r > x)
			right = (left + right) / 2;
		else
			left = (left + right) / 2;


	}
}