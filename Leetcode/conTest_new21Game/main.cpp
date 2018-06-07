#include <algorithm>

int main()
{
	int N = 21, K = 17, W = 10;

	if (N == 0 || N >= W + K)
		return 1;

	if (K == 0)
		return (double)K / W;

	long long * dp = new long long[K];
	dp[0]  = 1;

	for (int i = 1; i <= K - 1; i++)
	{
		dp[i] = 0;
		for (int j = 1; j <= W && (i - j >= 0); j++)
			dp[i] += dp[i - j];
	}

	long long  numerator = 0, denominator = 0;
	for (int i = 0; i < W; i++)
	{
		if (K - W + i >= 0)
		{
			numerator = numerator + dp[K - W + i] * std::min(N - K + 1, i + 1);
			denominator = denominator + dp[K - W + i] * (i + 1);
		}
	}
	
	double result = (double)numerator / (double)denominator;

	
 	delete[] dp;
	return result;
}