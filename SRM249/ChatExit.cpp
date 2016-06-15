// https://community.topcoder.com/stat?c=problem_statement&pm=4614&rd=7224
// This problem was used for: 
// Single Round Match 249 Round 1 - Division I, Level Two

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
class ChatExit
{
	public:
		vector<int> leaveOrder(vector<string> numSeen)
	{
		vector<vector<int> > numbs;
		for(int i=0; i<numSeen.size(); i++)
		{
			vector<int> seen;
			stringstream ss(numSeen[i]);
			int j;
			while(ss>>j)
			{
				seen.push_back(j);
				if(ss.peek()==' ') ss.ignore();
			}
			numbs.push_back(seen);
		}
		bool adj[25][25];
		for(int i=0; i<numbs.size(); i++)
		{
			for(int j=0; j<numbs.size(); j++)
			{
				adj[i][j] = false;
			}
		}
		for(int i=0; i<numbs.size(); i++)
		{
			for(int j=0; j<numbs.size()-1; j++)
			{
				if(j==i)continue;
				for(int k=j+1; k<numbs.size(); k++)
				{
					if(k==i) continue;
					if(numbs[k][i]>numbs[j][i])
					{
						adj[j][k] = true;
						adj[j][i] = true;
					}
					else if(numbs[k][i]<numbs[j][i])
					{
						adj[k][j] = true;
						adj[k][i] = true;
					}
				}
			}
		}
		//adj filled
		vector<int> result;
		int count = numSeen.size();
		while(count>0)
		{
			vector<int> candidates;
			for(int i=0; i<numSeen.size(); i++)
			{
				bool inDegreeIsZero = true;
				for(int j=0; j<numSeen.size(); j++)
				{
					if(adj[j][i])
					{
						inDegreeIsZero = false;
						break;
					}
				}
				if(inDegreeIsZero&&(find(result.begin(), result.end(), i)==result.end())) candidates.push_back(i);
			}
			if(candidates.size()==0)
			{
				return candidates;
			}
			sort(candidates.begin(), candidates.end());
			result.push_back(candidates[0]);
			count--;
			for(int i=0; i<numSeen.size(); i++)
			{
				adj[candidates[0]][i] = false;
			}
		}
		return result;
	}
};
