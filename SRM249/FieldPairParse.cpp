// https://community.topcoder.com/stat?c=problem_statement&pm=4615&rd=7224
// This problem was used for: 
// Single Round Match 249 Round 1 - Division II, Level Two

#include <string>
#include <vector>
using namespace std;
class FieldPairParse
{
	public:
	vector<int> getPairs(vector<string> data)
	{
		vector<bool> combine;
		for(int i=0; i<data[0].length(); i++)
		{
			if(data[0][i]==' ')combine.push_back(true);
			else combine.push_back(false);
		}
		for(int i=1; i<data.size(); i++)
		{
			for(int j=0; j<data[i].length(); j++)
			{
				bool temp = data[i][j]==' ';
				combine[j] = combine[j] && temp;
			}
		}
		vector<int> result;
		int count = 0;
		for(int i=0; i<combine.size(); i++)
		{
			if(combine[i])
			{
				count++;
			}
			else
			{
				if(count>0)
				{
					result.push_back(count);
					count = 0;
				}
			}
		}
		if(result.size()%2==0)
		{
			result.clear();
		}
		return result;
	}
};
