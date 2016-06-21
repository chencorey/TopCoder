// https://community.topcoder.com/stat?c=problem_statement&pm=8161&rd=12170
// This problem was used for: 
// Single Round Match 398 Round 1 - Division II, Level One


#include <algorithm>
#include <cmath>
using namespace std;
class MinDifference
{
	public:
	int closestElements(int A0, int X, int Y, int M, int n)
	{
		vector<int> items;
		items.push_back(A0);
		for(int i = 1; i<n; i++)
		{
			long temp = (((long)items[i-1])*X + Y)%M;
			items.push_back(temp);
		}
		int overallmin = 10000;
		for(int i = 0; i<items.size();i++)
		{
			for(int j = i+1; j<items.size(); j++)
			{
				if(abs(items[i]-items[j])<overallmin)
				{
					overallmin = abs(items[i]-items[j]);
				}
			}
		}
		return overallmin;
	}
};
