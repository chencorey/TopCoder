// https://community.topcoder.com/stat?c=problem_statement&pm=9753&rd=12183
// This problem was used for: 
// Single Round Match 411 Round 1 - Division II, Level One

#include <algorithm>
using namespace std;
class MaximumScoredNumber
{
	public:
	int getNumber(int lowerBound, int upperBound)
	{
		int count = 0;
		int num = 0;
		for(int i = lowerBound; i<=upperBound; i++)
		{
			int curr = 0;
			for(int j = 0; j*j<=i; j++)
			{
				for(int k = j; k*k<=i; k++)
				{
					if(j*j+k*k==i) curr++;
				}
			}
			if(curr>=count)
			{
				count = curr;
				num = i;
			}
		}
		return num;
	}
};
