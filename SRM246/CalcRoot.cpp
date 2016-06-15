// https://community.topcoder.com/stat?c=problem_statement&pm=4519&rd=7221
// This problem was used for: 
// Single Round Match 246 Round 1 - Division I, Level Three
// Note: Fails on a few test cases

#include <string>
#include <cmath>
#include <climits>
using namespace std;
class CalcRoot
{
	public:
	string approximate(int N, int D)
	{
		double target = sqrt((double)N);
		double distance = 2;
		string result;
		for(int i=1; i<=D; i++)
		{
			double numerator = target*(double)i;
			double value = round(numerator)/i-target;
			if(abs(value)<distance) 
			{
				result = to_string((int)round(numerator)) + "/" + to_string(i);
				distance = abs(value);
			}
		}
		return result;
	}
};
