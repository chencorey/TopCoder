// https://community.topcoder.com/stat?c=problem_statement&pm=4487&rd=7220
// This problem was used for: 
// Single Round Match 245 Round 1 - Division I, Level One 
// Single Round Match 245 Round 1 - Division II, Level Two

#include <algorithm>
using namespace std;

class Flush
{
	public:
	double choose(int n, int k)
{
	double result = 1;
	for (int i = n; i > max(k, n - k); i--)
	{
		result = result * i;
	}
	for (int i = 2; i <= min(k, n - k); i++)
	{
		result = result / i;
	}
	return result;
}
double size(vector<int> suits, int number)
{
	double denom = 0;
	double max_counts[14];
	for (int i = 0; i<14; i++)
	{
		max_counts[i] = 0;
	}
	for (int i = 0; i <= min(suits[0], number); i++)
	{
		for (int j = 0; j <= min(suits[1], number - i); j++)
		{
			for (int k = 0; k <= min(suits[2], number - i - j); k++)
			{
				if (number - i - j - k<=suits[3])
				{
					int max_num = max(max(max(i, j), k), number - i - j - k);
					double ways = choose(suits[0], i)* choose(suits[1], j)* choose(suits[2], k) * choose(suits[3], number - i - j - k);
					denom += ways;
					max_counts[max_num] += ways;
				}
			}
		}
	}
	double sigma = 0;
	for (int i = 1; i<14; i++)
	{
		sigma += max_counts[i] * i;
	}
	return sigma / denom;
}
};
