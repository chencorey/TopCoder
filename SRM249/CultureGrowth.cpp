// https://community.topcoder.com/stat?c=problem_statement&pm=3996&rd=7224
// This problem was used for: 
// Single Round Match 249 Round 1 - Division I, Level Three

#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class CultureGrowth
{
	public:
bool isClockwise(int x1, int y1, int x2, int y2, int x3, int y3)
	{
		return ((y2-y1)*(x3-x2)-(x2-x1)*(y3-y2))>=0;
	}
	double finalTray(vector<int> xs, vector<int> ys)
	{
		if(xs.size()<3) return 0;
		vector<int> xHull;
		vector<int> yHull;
		int leftmostPointIndex = -1;
		int leftmostPoint = INT_MAX;
		for(int i=0; i<xs.size(); i++)
		{
			if(xs[i]<leftmostPoint)
			{
				leftmostPoint = xs[i];
				leftmostPointIndex = i;
			}
		}
		int ip = leftmostPointIndex;
		int iq;
		do
		{
			xHull.push_back(xs[ip]);
			yHull.push_back(ys[ip]);
			iq = (ip+1)%xs.size();
			for(int i=0; i<xs.size(); i++)
			{

				if(!isClockwise(xs[ip], ys[ip], xs[i], ys[i], xs[iq], ys[iq]))
				{
					iq = i;
				}
			}
			ip = iq;
		} while(ip!=leftmostPointIndex);
		double area = 0;
		int j = xHull.size()-1;
		for(int i=0; i<xHull.size(); i++)
		{
			area+=(xHull[j] + xHull[i]) * (yHull[j]-yHull[i]);
			j=i;
		}
		return -area/2;
	}
};
