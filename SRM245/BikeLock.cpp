// https://community.topcoder.com/stat?c=problem_statement&pm=4572&rd=7220
// This problem was used for: 
// Single Round Match 245 Round 1 - Division I, Level Two

#include <vector>
#include <string>
using namespace std;
class BikeLock
{
	public:
	int minTurns(string current, string desired)
	{
		vector<int> diff;
		for(int i=0; i<current.length(); i++)
		{
			diff.push_back((current[i]-desired[i]+10)%10);
		}
		int turns = 0;
		int count = 0;
		int prev = -1;
		int skip = -1;
		for(int i=0; i<diff.size(); i++)
		{
			if(diff[i]==0)
			{
				prev = -1;
				continue;
			}
			if(i==skip)
			{
				prev = -1;
				continue;
			}
			if(diff[i]!=prev)
			{
				turns++;
				count=1;
				prev = diff[i];
				if(i+2<diff.size())
				{
					if(diff[i+2]==diff[i])skip = i+2;
				}
			}
			else
			{
				count++;
				if(count==3) prev = -1;
			}
		}
		return turns;
	}
};
