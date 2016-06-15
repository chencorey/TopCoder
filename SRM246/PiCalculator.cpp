// https://community.topcoder.com/stat?c=problem_statement&pm=4470&rd=7221
// This problem was used for: 
// Single Round Match 246 Round 1 - Division I, Level One

#include <string>
using namespace std;
class PiCalculator
{
	public:
	string calculate(int precision)
	{
		string pi = "3.141592653589793238462643383279";
		if(pi[precision+2]<'5')
		{
			return pi.substr(0, precision + 2);
		}
		else
		{
			if(precision==12)
			{
				return "3.141592653590";
			}
			else
			{
				pi[precision+1]++;
				return pi.substr(0, precision+2);
			}
		}
	}
};
