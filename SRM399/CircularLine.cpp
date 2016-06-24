// https://community.topcoder.com/stat?c=problem_statement&pm=8761&rd=12171
// This problem was used for: 
// Single Round Match 399 Round 1 - Division II, Level One

#include <vector>
#include <algorithm>
using namespace std;
class CircularLine
{
	public:
	int longestTravel(vector<int> t)
	{
		int max = 0;
		for(int i = 0; i<t.size(); i++)
		{
			for(int j = i+1; j<t.size(); j++)
			{
				int count = 0;
				for(int k = i; k<j; k++)
				{
					count+=t[k];
				}
				int count2 = 0;
				for(int k = j; k<i+t.size(); k++)
				{
					count2+=t[k%t.size()];
				}
				if(min(count, count2)>max)
				{
					max = min(count, count2);
				}
			}
		}
		return max;
	}
};
