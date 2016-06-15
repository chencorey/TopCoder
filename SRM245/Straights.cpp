// https://community.topcoder.com/stat?c=problem_statement&pm=4561&rd=7220
// This problem was used for: 
// Single Round Match 245 Round 1 - Division II, Level One

#include <vector>
using namespace std;
class Straights
{
	public:
	int howMany(vector<int> hand, int k)
	{
		int count = 0;
		for(int i=0; i<=13-k; i++)
		{
			int hc = 1;
			for(int j=i; j<i+k; j++)
			{
				hc = hc*hand[j];
			}
			count+=hc;
		}
		return count;
	}
};
