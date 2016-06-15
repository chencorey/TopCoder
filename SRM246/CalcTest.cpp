// https://community.topcoder.com/stat?c=problem_statement&pm=4469&rd=7221
// This problem was used for: 
// Single Round Match 246 Round 1 - Division II, Level One

#include <vector>
#include <string>
using namespace std;

class CalcTest{
	public:
	vector<string> uniform(vector<string> numbers)
	{
		vector<string> result;
		for(int i=0; i<numbers.size(); i++)
		{
			string modified;
			for(int j=0; j<numbers[i].length(); j++)
			{
				if(numbers[i][j]>='0'&&numbers[i][j]<='9')
				{
					modified = modified + numbers[i][j];
				}
				else if(numbers[i][j]!=' ')
				{
					modified = modified + ".";
				}
			}
			result.push_back(modified);
		}
		return result;
	}
};
