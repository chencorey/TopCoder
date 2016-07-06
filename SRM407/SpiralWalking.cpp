// https://community.topcoder.com/stat?c=problem_statement&pm=9793&rd=12179
// This problem was used for: 
// Single Round Match 407 Round 1 - Division II, Level One

#include <vector>
#include <string>
using namespace std;
class SpiralWalking
{
	public:
	int totalPoints(vector<string> grid)
	{
		int cLow = 0;
		int cHigh = grid[0].length();
		int rLow = 0;
		int rHigh = grid.size();
		int currR = 0;
		int currC = 0;
		int currD = 0;
		int numPoints = (cHigh)*(rHigh);
		int total = 0;
		while(numPoints>0)
		{
			if(currD==0)
			{
				for(int i = cLow; i<cHigh; i++)
				{
					currC = i;
					numPoints--;
					if(i==cHigh-1) continue;
					total+=grid[currR][i]-'0';
				}
				rLow++;
				currD++;
			}
			else if(currD==1)
			{
				for(int i = rLow; i<rHigh; i++)
				{
					currR = i;
					numPoints--;
					if(i==rHigh-1) continue;
					total+=grid[i][currC]-'0';
				}
				cHigh--;
				currD++;
			}
			else if(currD==2)
			{
				for(int i = cHigh-1; i>=cLow; i--)
				{
					currC = i;
					numPoints--;
					if(i==cLow) continue;
					total+=grid[currR][i]-'0';
				}
				rHigh--;
				currD++;
			}
			else if(currD==3)
			{
				for(int i = rHigh-1; i>=rLow; i--)
				{
					currR = i;
					numPoints--;
					if(i==rLow) continue;
					total+=grid[i][currC]-'0';
				}
				cLow++;
				currD=0;
			}
		}
		total+=grid[currR][currC]-'0';
		return total;
	}
};
