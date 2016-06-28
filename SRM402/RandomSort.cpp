// https://community.topcoder.com/stat?c=problem_statement&pm=8590&rd=12174
// This problem was used for: 
// Single Round Match 402 Round 1 - Division I, Level One 
// Single Round Match 402 Round 1 - Division II, Level Three

#include <vector>
#include <map>
using namespace std;
class RandomSort
{
	public:
	map<vector<int>, double> checker;
	double getExpected(vector<int> curr)
	{
		int count = 0;
		double sum = 0;
		for(int i = 0; i<curr.size(); i++)
		{
			for(int j = i + 1; j<curr.size(); j++)
			{
				if(curr[i]>curr[j])
				{				
					vector<int> temp(curr.begin(), curr.end());
					int h = temp[i];
					temp[i] = temp[j];
					temp[j] = h;
					count++;
					if(checker.find(temp)==checker.end())
					{
						checker[temp] = getExpected(temp);
					}
					sum+=checker[temp];
				}
			}
		}
		if(count==0) return 0;
		return 1+sum/count;
	}
	
};
