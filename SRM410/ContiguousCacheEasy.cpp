// https://community.topcoder.com/stat?c=problem_statement&pm=9729&rd=12182
// This problem was used for: 
// Single Round Match 410 Round 1 - Division II, Level One

#include <vector>
#include <algorithm>
using namespace std;
class ContiguousCacheEasy
{
	public:
	int bytesRead(int n, int k, vector<int> addresses)
	{
		int low = 0;
		int high = k-1;
		int count = 0;
		for(int i = 0; i<addresses.size(); i++)
		{
			if(addresses[i]<low)
			{
				count += min(k, low-addresses[i]);
				low = addresses[i];
				high = addresses[i]+k-1;				
			}
			else if(addresses[i]>high)
			{
				count += min(k, addresses[i]-high);
				high = addresses[i];
				low = addresses[i]-k+1;	
			}
		}
		return count;
	}
};
