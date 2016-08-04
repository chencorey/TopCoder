// https://community.topcoder.com/stat?c=problem_statement&pm=10033&rd=13513
// This problem was used for: 
// Single Round Match 422 Round 1 - Division I, Level One 
// Single Round Match 422 Round 1 - Division II, Level Two

#include <algorithm>
#include <cmath>
using namespace std;
class PrimeSoccer
{
	public:
	double choose(int n, int k)
	{
		double result = 1;
		for(int i = 2; i<=n; i++)
		{
			result*=i;
		}
		for(int i = 2; i<=k; i++)
		{
			result/=i;
		}
		for(int i = 2; i<=n-k; i++)
		{
			result/=i;
		}
		return result;
	}
	double getProbability(int skillA, int skillB)
	{//{2, 3, 5, 7, 11, 13, 17};
		int notPrimes[12] = {0, 1, 4, 6, 8, 9, 10, 12, 14, 15, 16, 18};
		double ANotPrime = 0;
		double BNotPrime = 0;
		for(int i = 0; i<12; i++)
		{
			ANotPrime += choose(18, notPrimes[i]) * pow(((double)skillA)/100, notPrimes[i]) * pow(1-((double)skillA)/100, 18-notPrimes[i]);
			BNotPrime += choose(18, notPrimes[i]) * pow(((double)skillB)/100, notPrimes[i]) * pow(1-((double)skillB)/100, 18-notPrimes[i]);
		}
		return 1-ANotPrime*BNotPrime;
	}
};
