// https://community.topcoder.com/stat?c=problem_statement&pm=9933&rd=13506
// This problem was used for: 
// Single Round Match 415 Round 1 - Division I, Level One

#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
class ShipLoading
{
	public:
	int minimumTime(vector<int> cranes, vector<string> boxes)
	{
		stringstream ss;
		for(int i = 0; i<boxes.size(); i++)
		{
			ss<<boxes[i];
		}
		vector<int> bs;
		int temp;
		while(ss>>temp)
		{
			bs.push_back(temp);
		}
		sort(bs.begin(), bs.end());
		int time = 0;
		while(bs.size()>0)
		{
			bool progress = false;
			time++;
			for(int i = 0; i<cranes.size(); i++)
			{
				int jt = -1;
				for(int j =0; j<bs.size(); j++)
				{					
					if(cranes[i]<bs[j])
					{
						break;
					}
					jt = j;
				}
				if(jt!=-1)
				{
					progress = true;
					bs.erase(bs.begin()+jt);
				}
			}
			if(!progress) return -1;
		}
		return time;
	}

};
