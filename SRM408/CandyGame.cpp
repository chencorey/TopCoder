// https://community.topcoder.com/stat?c=problem_statement&pm=8462&rd=12180
// This problem was used for: 
// Single Round Match 408 Round 1 - Division I, Level Two

#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class CandyGame
{
	public:
	vector<string> g;
	bool visited[50];
	int explore(int node, int maxCandy, int ori)
	{
		visited[node] = true;
		int mostCandy = (1<<maxCandy)-1;
		if(maxCandy>30) return -1;
		int best = -1;
		vector<int> currVisited;
		for(int i = 0; i<g[node].length(); i++)
		{
			if(g[node][i]=='Y'&&i!=ori)
			{
				currVisited.push_back(i);
				int targetCandy = explore(i, maxCandy+1, node);
				if(targetCandy==-1) return -1;
				if(targetCandy>mostCandy)
				{
					mostCandy = targetCandy;
					best = currVisited.size()-1;
				}
			}
		}
		if(currVisited.size()==0) return mostCandy;
		long long result = 0;
		result+=mostCandy;
		for(int i = 0; i<currVisited.size(); i++)
		{
			if(best!=i)
			result+=explore(currVisited[i], 1, node);
			if(result>2000000000) return -1;
		}
		return result;
	}
	int maximumCandy(vector<string> graph, int target)
	{
		g = graph;
		for(int i = 0; i<graph.size(); i++) visited[i] = false;
		int result = explore(target, 0, -1);
		for(int i = 0; i<graph.size(); i++)
		{
			if(!visited[i]) return -1;
		}
		return result;
	}
};
