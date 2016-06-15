// https://community.topcoder.com/stat?c=problem_statement&pm=4502&rd=7220
// This problem was used for: 
// Single Round Match 245 Round 1 - Division II, Level Three

#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;
class CardCosts{
public:
long long mincost(int n, int k)
{
	if (k == 1)
	{
		return (long long)n;
	}
	long rounds[40];
	long long lastcalc[40];
	for (int i = 0; i < 40; i++)
	{
		rounds[i] = 0;
		lastcalc[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		long long min = LLONG_MAX;
		int minIndex = 0;
		for (int j = 0; j < 40; j++)
		{
			long long cost = 0;
			if (lastcalc[j] == 0)
			{
				cost = (long long)pow(k, j) * (rounds[j] * 2 + 1);
				lastcalc[j] = cost;
			}
			else
			{
				cost = lastcalc[j];
			}
			if (cost < min)
			{
				minIndex = j;
				min = cost;
			}
			if (cost < (long long)pow(k, j + 1))
			{
				break;
			}
		}
		rounds[minIndex]++;
		lastcalc[minIndex] = 0;
	}
	long long totalcost = 0;
	for (int i = 0; i < 40; i++)
	{
		totalcost += (long long)pow(k, i) * pow(rounds[i], 2);
	}
	return totalcost;
}
};
