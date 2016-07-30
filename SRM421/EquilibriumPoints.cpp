// https://community.topcoder.com/stat?c=problem_statement&pm=10104&rd=13512
// This problem was used for: 
// Single Round Match 421 Round 1 - Division I, Level One 
// Single Round Match 421 Round 1 - Division II, Level Two 
// TCHS Single Round Match 59 Round 1 - Division I, Level Two

#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const double eps = 1e-15;
bool isZero(double a)
{
	return abs(a)<eps;
}
class EquilibriumPoints
{
	public:
	vector<int> xc;
	vector<int> ms;
	double pos(double low, double high, int numLeft)
	{
		double mid = high-(high-low)/2;
		if(isZero(mid-low)||isZero(high-mid)) return mid;
		double force = 0;
		for(int i = 0; i<numLeft; i++)
		{
			force+=((double)ms[i])/((mid-xc[i])*(mid-xc[i]));
		}
		for(int i = numLeft; i<ms.size(); i++)
		{
			force-=((double)ms[i])/((mid-xc[i])*(mid-xc[i]));
		}
		if(isZero(force)) return mid;
		else if(force>0)
		{
			return pos(mid, high, numLeft);
		}
		else
		{
			return pos(low, mid, numLeft);
		}
	}
	vector<double> getPoints(vector<int> x, vector<int> m)
	{
		xc = x;
		ms = m;
		vector<double> result;
		for(int i = 1; i<x.size(); i++)
		{
			double temp = pos(x[i-1], x[i], i);
			result.push_back(temp);
		}
		return result;
	}
};
