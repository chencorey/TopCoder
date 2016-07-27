// https://community.topcoder.com/stat?c=problem_statement&pm=9902&rd=13507
// This problem was used for: 
// Single Round Match 416 Round 1 - Division II, Level Three

#include <vector>
#include <string>
using namespace std;
class DancingCouples
{
	public:
	vector<string> cD;
	int memo[1024][1024];
	int pair2(vector<int> bComb, vector<int> gComb, int r)
	{
		if(r==-1)
		{
			return 1;
		}
		int bMask = 0;
		for(int i = 0; i<bComb.size(); i++)
		{
			bMask+=(1<<bComb[i]);
		}
		int gMask = 0;
		for(int i = 0; i<gComb.size(); i++)
		{
			gMask+=(1<<gComb[i]);
		}
		if(memo[bMask][gMask]!=-1)
		{
			return memo[bMask][gMask];
		}		
		else
		{
			int c = 0;
			for(int i = 0; i<gComb.size(); i++)
			{
				if(cD[bComb[r]][gComb[i]]=='Y')
				{
					vector<int> temp = gComb;
					temp.erase(temp.begin()+i);
					c+=pair2(bComb, temp, r-1);
				}
			}
			memo[bMask][gMask] = c;
			return c;
		}
	}
	int countPairs(vector<string> canDance, int K)
	{
		for(int i = 0; i<1024; i++)
		{
			for(int j = 0; j<1024; j++)
			{
				memo[i][j] = -1;
			}
		}
		cD = canDance;
		vector<vector<int> > boysComb;
		for(int i = 0; i<(1<<canDance.size()); i++)
		{
			vector<int> comb;
			for(int j = 0; j<canDance.size(); j++)
			{
				if((i&(1<<j))>0)
				{
					comb.push_back(j);
				}
			}
			if(comb.size()==K)
			{
				boysComb.push_back(comb);
			}
		}
		
		vector<vector<int> > girlsComb;
		for(int i = 0; i<(1<<canDance[0].length()); i++)
		{
			vector<int> comb;
			for(int j = 0; j<canDance[0].length(); j++)
			{
				if((i&(1<<j))>0)
				{
					comb.push_back(j);
				}
			}
			if(comb.size()==K)
			{
				girlsComb.push_back(comb);
			}
		}
		int result = 0;
		for(int i = 0; i<boysComb.size(); i++)
		{
			for(int j = 0; j<girlsComb.size(); j++)
			{
				result+=pair2(boysComb[i], girlsComb[j], K-1);
			}
		}
		return result;
	}
};
