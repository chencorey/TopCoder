// https://community.topcoder.com/stat?c=problem_statement&pm=8784&rd=12178
// This problem was used for: 
// Single Round Match 406 Round 1 - Division I, Level One

#include <vector>
#include <algorithm>
using namespace std;
class SymmetricPie
{
	public:
	int getLines(vector<int> dogs)
	{
		int result = 0;
		sort(dogs.begin(), dogs.end());
  		do
  		{
			int count = 0;
			for(int i = 0; i<dogs.size(); i++)
			{
				for(int j = 1; j<dogs.size(); j++)
				{
					int total = 0;
					for(int k = i; k<i+j; k++)
					{
						total+=dogs[k%dogs.size()];
					}
					if(total==50)count++;
				}
			}
			result = max(result, count);
		}
		while(next_permutation(dogs.begin(), dogs.end()));
		return result/2;
	}
};
