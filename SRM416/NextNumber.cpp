// https://community.topcoder.com/stat?c=problem_statement&pm=8576&rd=13507
// This problem was used for: 
// Single Round Match 416 Round 1 - Division I, Level One 
// Single Round Match 416 Round 1 - Division II, Level Two

#include <vector>
using namespace std;
class NextNumber
{
	public:
	int getNextNumber(int N)
	{
		int index = -1;
		while(true)
		{
			index++;
			if((N&(1<<index))>0)
			{
				break;
			}
		}
		int index2 = index;
		while(true)
		{
			index2++;
			if((N&(1<<index2))==0)
			{
				break;
			}
		}
		int index3 = index2;
		while(true)
		{
			index3--;
			if((N&(1<<index3))>0)
			{
				break;
			}
		}
		vector<int> indices;
		int index4 = index3;
		while(index4>=0)
		{
			index4--;
			if((N&(1<<index4))>0)
			{
				indices.push_back(index4);
			}
		}
		int result = N - (1<<index3) + (1<<index2);
		for(int i = 0; i<indices.size(); i++)
		{
			result-=(1<<indices[i]);
			result+=(1<<i);
		}
		return result;
	}
};
