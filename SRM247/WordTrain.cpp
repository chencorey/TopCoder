// https://community.topcoder.com/stat?c=problem_statement&pm=875&rd=7222
// This problem was used for: 
// Single Round Match 247 Round 1 - Division I, Level Two
// Note: Fails on a few test cases

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b)
{
	if(a[0]==b[0])
	{
		if(a[0]==a[a.length()-1] && b[0]!=b[b.length()-1])
		{
			return true;
		}
		else if(b[0]==b[b.length()-1] && a[0]!=a[a.length()-1])
		{
			return false;
		}
		else
		{
			return a<b;
		}
	}
	else
	{
		return a[0]<b[0];
	}
}
class WordTrain
{
	public:
	
	string hookUp(vector<string> cars)
	{
		for(int i=0; i<cars.size(); i++)
		{
			string reversed = "";
			for(int j=cars[i].length()-1; j>=0; j--)
			{
				reversed = reversed + cars[i][j];
			}
			if(cars[i]>reversed)
			{
				cars[i] = reversed;
			}
		}
		sort(cars.begin(), cars.end(), cmp);
		string dp[50];
		dp[0]=cars[0];
		for(int i=1; i<cars.size(); i++)
		{
			vector<string> candidates;
			int max = -1;
			for(int j=0; j<i; j++)
			{
				if(dp[j][dp[j].length()-1]==cars[i][0])
				{
					int count = 0;
					for(int k=0; k<dp[j].length(); k++)
					{
						if(dp[j][k]=='-') count++;
					}
					if(count>max)
					{
						candidates.clear();
						candidates.push_back(dp[j]);
						max = count;
					}
					if(count==max)
					{
						candidates.push_back(dp[j]);
					}					
				}
			}
			if(candidates.size()==0) dp[i] = cars[i];
			else
			{
				sort(candidates.begin(), candidates.end());
				dp[i] = candidates[0] + "-"+cars[i];
			}
		}
		int l = -1;
		int ind = -1;
		for(int i=0; i<cars.size(); i++)
		{
			int count = 0;
			for(int j=0; j<dp[i].length(); j++)
			{
				if(dp[i][j]=='-') count++;
			}
			if(count>l)
			{
				ind = i;
				l = count;
			}
		}
		return dp[ind];
	}
};
