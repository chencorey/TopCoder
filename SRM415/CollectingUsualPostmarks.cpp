// https://community.topcoder.com/stat?c=problem_statement&pm=9978&rd=13506
// This problem was used for: 
// Single Round Match 415 Round 1 - Division II, Level One

#include <vector>
#include <algorithm>
using namespace std;
class CollectingUsualPostmarks
{
	public:
	int numberOfPostmarks(vector<int> prices, vector<int> have)
	{
		long long money = 0;
		for(int i = 0; i<have.size(); i++)
		{
			money+=prices[have[i]];
		}
		sort(prices.begin(),prices.end());
		int i = 0;
		for(i = 0; prices[i]<=money&&i<prices.size(); i++)
		{
			money-=prices[i];
		}
		return i;
	}
};
