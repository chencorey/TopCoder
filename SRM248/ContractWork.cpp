// https://community.topcoder.com/stat?c=problem_statement&pm=3525&rd=7223
// This problem was used for: 
// Single Round Match 248 Round 1 - Division I, Level Two

#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

class ContractWork
{
	public:
	int minimumCost(vector<string> ccosts, int numTasks)
	{
		int cost[50][50];
		for(int i=0; i<ccosts.size(); i++)
		{
			int j=0;
			int index = 0;
			while(j<ccosts[i].length())
			{
				for(int k=j+1; k<=ccosts[i].length(); k++)
				{
					if(ccosts[i][k]==' '||k==ccosts[i].length())
					{
						cost[i][index] = stoi(ccosts[i].substr(j, k-j));
						j=k+1;
						index++;
						break;
					}
				}
			}
		}
		int dp[50][50][50];
		for(int j = 0; j<ccosts.size(); j++)
		{
			for(int k=0; k<ccosts.size(); k++)
			{
				int best = INT_MAX/2;
				for(int i=0; i<ccosts.size(); i++)
				{
					if(j==k && i==j) continue;
					best = min(best, cost[i][numTasks-1]);
				}
				dp[j][k][numTasks-1] = best;
			}
		}
		for(int i = numTasks-2; i>=0; i--)
		{
			for(int j=0; j<ccosts.size(); j++)
			{
				for(int k=0; k<ccosts.size(); k++)
				{
					int best = INT_MAX;
					for(int l = 0; l<ccosts.size(); l++)
					{
						if(j==k && j==l) continue;
						best = min(best, cost[l][i] + dp[k][l][i+1]);
					}
					dp[j][k][i] = best;
				}
			}
		}
		int result = INT_MAX;
		for(int j=0; j<ccosts.size(); j++)
		{
			for(int k=0; k<ccosts.size(); k++)
			{
				result = min(result, dp[j][k][0]);
			}
		}
		return result;
	}

};
