// https://www.topcoder.com/tc?module=Static&d1=match_editorials&d2=srm405
// This problem was used for: 
// Single Round Match 405 Round 1 - Division I, Level Two

#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class AllCycleLengths
{
	public:
	string findAll(vector<string> arcs)
	{
		bool hasEdge[30][30];
		for(int i = 0; i<arcs.size(); i++)
		{
			for(int j = 0; j<arcs[i].length(); j++)
			{
				hasEdge[i][j] = arcs[i][j]=='Y';
			}
		}
		bool poss[1000];
		for(int i = 0; i<1000; i++)
		{
			poss[i] = false;
		}
		for(int node = 0; node < arcs.size(); node++)
		{
			int time = 1;
			vector<int> BFSnodes;			
			BFSnodes.push_back(node);
			while(time<1000)
			{
				vector<int> nextNodes;
				for(int i = 0; i<BFSnodes.size(); i++)
				{
					for(int j = 0; j<arcs.size(); j++)
					{
						if(hasEdge[BFSnodes[i]][j]&&find(nextNodes.begin(), nextNodes.end(), j)==nextNodes.end())
						{
							nextNodes.push_back(j);
							if(j==node) poss[time] = true;
						}
					}
				}
				BFSnodes = nextNodes;
				time++;
			}
		}
		bool check = true;
		int iResult = 5000;
		int iPattern;
		int iInit;
		for(int i = 0; i<1000; i++)
		{
			for(int j = 1; j<1000-i; j++)
			{
				check = true;
				for(int k = i; k<1000; k++)
				{
					if(poss[k]!=poss[(k-i)%j+i])
					{
						check = false;
						break;
					}
				}
				if(check) 
				{
					if(i+j<iResult)
					{
						iPattern = j;
						iInit = i;
						iResult = i+j;
					}
				}
			}
		}
		string result;
		for(int i = 1; i<iInit; i++)
		{
			if(poss[i]) result+='1';
			else result+='0';
		}
		result+='(';
		for(int i = iInit; i<iInit+iPattern; i++)
		{
			if(poss[i]) result+='1';
			else result+='0';
		}
		result+=')';
		return result;
	}

};
