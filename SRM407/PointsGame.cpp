// https://community.topcoder.com/stat?c=problem_statement&pm=9791&rd=12179
// This problem was used for: 
// Single Round Match 407 Round 1 - Division I, Level Two

#include <utility>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
class PointsGame
{
	public:
	double dist[12][12];
	map<pair<int, int>, double> memo;
	int N;
	double solve(int set1, int set2, bool myTurn)
	{
		pair<int, int> p = make_pair(set1, set2);
		if(memo.find(p)!=memo.end()) return memo[p];
		if(set1+set2 == (1<<N)-1)
		{
			double total = 0;
			for(int i= 0; i<N; i++)
			{
				if(((1<<i)&set1)!=0)
				for(int j = 0; j<N; j++)
				{
					if(((1<<j)&set2)!=0)
					{
						total+=dist[i][j];
					}
				}
			}
			memo[p] = total;
			return total;
		}
		double result;
		if(myTurn) result = 0;
		else result = 1e100;
		for(int i = 0; i<N; i++)
		{
			if(((1<<i)&set1)==0&&((1<<i)&set2)==0)
			{
				double value = solve(set2, set1|(1<<i), !myTurn);
				if(myTurn) result = max(result, value);
				else result = min(result, value);
			}
		}
		memo[p] = result;
		return result;
	}
	double gameValue(vector<int> x, vector<int> y)
	{
		N = x.size();
		for(int i = 0; i<x.size(); i++)
		{
			for(int j = 0; j<x.size(); j++)
			{
				dist[i][j] = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
			}
		}
		return solve(0, 0, true);
	}
};
