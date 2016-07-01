// https://community.topcoder.com/stat?c=problem_statement&pm=9761&rd=12177
// This problem was used for: 
// Single Round Match 405 Round 1 - Division II, Level One


#include <algorithm>
class FallingFactorialPower
{
	public:
	double compute(int n, int k)
	{
		double result = 1;
		if(k==0) return 1;
		if(k<0)
		{
			for(int i = 1; i<=abs(k); i++)
			{
				result*=(n+i);
			}
			return ((double)1/result);
		}
		else
		{
			for(int i = n; i>=n-k+1; i--)
			{
				result *=i;
			}
			return result;
		}
	}
};
