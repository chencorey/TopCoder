// https://community.topcoder.com/stat?c=problem_statement&pm=8157&rd=12170
// This problem was used for: 
// Single Round Match 398 Round 1 - Division I, Level One 
// Single Round Match 398 Round 1 - Division II, Level Two

#include <string>
#include <cstring>
#include <vector>
using namespace std;
class CountExpressions
{
	public:
	vector<int> poss;
	void opnum(int ori, int xcount, int ycount, int x, int y)
	{
		if(xcount==2 && ycount==2)
		{
			poss.push_back(ori);
		}
		if(xcount<2)
		{
			opnum(ori+x, xcount+1, ycount, x, y);
			opnum(ori-x, xcount+1, ycount, x, y);
			opnum(ori*x, xcount+1, ycount, x, y);
		}
		if(ycount<2)
		{
			opnum(ori+y, xcount, ycount+1, x, y);
			opnum(ori-y, xcount, ycount+1, x, y);
			opnum(ori*y, xcount, ycount+1, x, y);
		}
	}
	int calcExpressions(int x, int y, int val)
	{
		opnum(x, 1, 0, x, y);
		opnum(y, 0, 1, x, y);
		int result = 0;
		for(int i = 0; i<poss.size(); i++)
		{
			if(poss[i]==val)result++;
		}
		return result;
	}
};
