// https://community.topcoder.com/stat?c=problem_statement&pm=8746&rd=12169
// This problem was used for: 
// Single Round Match 397 Round 1 - Division II, Level Three

#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
class CollectingMarbles
{
	public:
	int dp[1<<13][11][21];
	vector<int> marbleWts;
	int bagCapac;
	int noBags;
	int recurse(int mask, int currentBag, int remainingCapac)
	{
		if(currentBag==0) return 0;
		if(dp[mask][currentBag][remainingCapac]==-1)
		{
			dp[mask][currentBag][remainingCapac] = 0;
			for(int i = 0; i<marbleWts.size(); i++)
			{
				if((mask & (1<<i))==0 && marbleWts[i]<=remainingCapac)
				{
					dp[mask][currentBag][remainingCapac] = max(dp[mask][currentBag][remainingCapac],
						1+recurse(mask|(1<<i), currentBag, remainingCapac-marbleWts[i])); 
				}
			}
			dp[mask][currentBag][remainingCapac] = max(dp[mask][currentBag][remainingCapac],
						recurse(mask, currentBag-1, bagCapac)); 
		}
		return dp[mask][currentBag][remainingCapac];
	}
	int mostMarbles(vector<int> marbleWeights, int bagCapacity, int numberOfBags)
	{
		marbleWts = marbleWeights;
		bagCapac = bagCapacity;
		noBags = numberOfBags;
		memset(dp, -1, sizeof(dp[0][0][0])*(1<<13)*10*21);
		return recurse(0, noBags, bagCapac);
	}
};
