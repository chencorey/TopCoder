// https://community.topcoder.com/stat?c=problem_statement&pm=3545&rd=7223
// This problem was used for: 
// Single Round Match 248 Round 1 - Division II, Level Three

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class BitStrings
{
	public:
	int maxStrings(vector<string> list, int numZeroes, int numOnes)
	{
		int*** dp = new int**[numZeroes+1];
		for(int k=0; k<=numZeroes; k++)
		{
			dp[k] = new int*[numOnes+1];
			for(int i=0; i<=numOnes; i++)
			{
				dp[k][i] = new int[list.size()];
			}
		}
		for(int i=0; i<list.size(); i++)
		{
			dp[0][0][i] = 0;
		}
		int tzeroCount = 0;
		int toneCount = 0;
		for(int j=0; j<list[0].length(); j++)
		{
			if(list[0][j]=='0')tzeroCount++;
			else toneCount++;
		}
		for(int j=0; j<=numZeroes; j++)
		{
			for(int k=0; k<=numOnes; k++)
			{
				if(tzeroCount<=j && toneCount<=k)
				{
					dp[j][k][0] = 1;
				}
				else
				{
					dp[j][k][0] = 0;
				}
			}
		}
		for(int i=1; i<list.size(); i++)
		{
			int zeroCount = 0;
			int oneCount = 0;
			for(int j=0; j<list[i].length(); j++)
			{
				if(list[i][j]=='0')zeroCount++;
				else oneCount++;
			}
			for(int j=0; j<numZeroes+1; j++)
			{
				for(int k=0; k<numOnes+1; k++)
				{
					if(zeroCount<=j && oneCount<=k)
					{
						dp[j][k][i] = max(dp[j][k][i-1], dp[j-zeroCount][k-oneCount][i-1] + 1);
					}
					else
					{
						dp[j][k][i] = dp[j][k][i-1];
					}
				}
			}
		}
		return dp[numZeroes][numOnes][list.size()-1];
	}
};
