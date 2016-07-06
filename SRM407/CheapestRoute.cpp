// https://community.topcoder.com/stat?c=problem_statement&pm=9794&rd=12179
// This problem was used for: 
// Single Round Match 407 Round 1 - Division II, Level Three 
// TCHS Single Round Match 51 Round 1 - Division I, Level Three

#include <vector>
#include <algorithm>
using namespace std;
class CheapestRoute
{
	public:
	int cost[50][51];
	int numMoves[50][51];
	vector<int> cPrice;
	vector<int> enterC;
	vector<int> exitC;
	int tPrice;
	void explore(int cell, int numTPs)
	{
		for(int i = 0; i<numTPs; i++)
		{
			if(cost[cell][i]<cost[cell][numTPs]||(cost[cell][i]==cost[cell][numTPs]&&numMoves[cell][i]<=numMoves[cell][numTPs])) return;
		}
		for(int i = -1; i!=3; i=i+2)
		{
			if(cell+i>=0 && cell+i < cPrice.size()&&cPrice[cell+i]!=-1)
			{		
				if(cost[cell+i][numTPs]>cost[cell][numTPs]+cPrice[cell+i]||
					(cost[cell+i][numTPs]==cost[cell][numTPs]+cPrice[cell+i]&&numMoves[cell+i][numTPs]>numMoves[cell][numTPs]+1))
				{
					cost[cell+i][numTPs]=cost[cell][numTPs]+cPrice[cell+i];
					numMoves[cell+i][numTPs]=numMoves[cell][numTPs]+1;
					explore(cell+i, numTPs);
				}
			}
		}
		//try teleports
		for(int i = 0; i<enterC.size(); i++)
		{
			if(enterC[i]==cell&&cPrice[exitC[i]]!=-1)
			{
				if(cost[exitC[i]][numTPs+1]>cost[cell][numTPs]+tPrice+numTPs||
					(cost[exitC[i]][numTPs+1]==cost[cell][numTPs]+tPrice+numTPs&&numMoves[exitC[i]][numTPs+1]>numMoves[cell][numTPs]+1))
				{
					cost[exitC[i]][numTPs+1]=cost[cell][numTPs]+tPrice+numTPs;
					numMoves[exitC[i]][numTPs+1]=numMoves[cell][numTPs]+1;
					explore(exitC[i], numTPs+1);
				}
			}
		}
	}
	vector<int> routePrice(vector<int> cellPrice, vector<int> enterCell, vector<int> exitCell, int teleportPrice)
	{
		cPrice = cellPrice;
		enterC = enterCell;
		exitC = exitCell;
		tPrice = teleportPrice;
		for(int i = 0; i<cellPrice.size(); i++)
		{
			for(int j = 0; j<=enterCell.size(); j++)
			{
				cost[i][j] = 1000000000;
				numMoves[i][j] = 1000000000;
			}
		}
		cost[0][0] = 0;
		numMoves[0][0] = 0;
		explore(0, 0);
		int minCost = 2000000000;
		int minMoves = 1000000000;
		for(int i = 0; i<=enterCell.size(); i++)
		{
			if(cost[cellPrice.size()-1][i]<minCost||(cost[cellPrice.size()-1][i]==minCost&&numMoves[cellPrice.size()-1][i]<minMoves))
			{
				minCost = cost[cellPrice.size()-1][i];
				minMoves = numMoves[cellPrice.size()-1][i];
			}
		}
		vector<int> result;
		if(minCost>=1000000000) return result;
		result.push_back(minCost);
		result.push_back(minMoves);
		return result;
	}
};
