// https://community.topcoder.com/stat?c=problem_statement&pm=8786&rd=13505
// This problem was used for: 
// Single Round Match 414 Round 1 - Division II, Level One

#include <vector>
#include <algorithm>
using namespace std;
class RestaurantManager
{
	public:
	int allocateTables(vector<int> tables, vector<int> groupSizes, vector<int> arrivals, vector<int> departures)
	{
		int result = 0;
		int occupied[50];
		for(int i = 0; i<tables.size(); i++)
		{
			occupied[i] = -1;
		}
		int lastArrivalTime = -1;
		for(int i = 0; i<arrivals.size(); i++)
		{
			//search if a group has left between current arrival time and last arrival time, and free tables
			for(int j = 0; j<departures.size(); j++)
			{			
				if(departures[j]>lastArrivalTime&&departures[j]<=arrivals[i])
				{
					for(int k = 0; k<tables.size(); k++)
					{
						if(occupied[k]==j) occupied[k] = -1;
					}
				}
			}
			//seat this arrival
			int diff = 200;
			int index = -1;
			for(int k = 0; k<tables.size(); k++)
			{
				if(occupied[k]==-1&&tables[k]>=groupSizes[i]&&tables[k]-groupSizes[i]<diff)
				{
					index = k;
					diff = tables[k]-groupSizes[i];
				}
			}
			if(index==-1)
			{
				result+=groupSizes[i];
			}
			else
			{
				occupied[index] = i;
			}
		}
		return result;
	}
};
