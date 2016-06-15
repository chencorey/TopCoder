// https://community.topcoder.com/stat?c=problem_statement&pm=4610&rd=7222
// This problem was used for: 
// Single Round Match 247 Round 1 - Division II, Level One

#include <string>
#include <algorithm>
using namespace std;
class TriangleType
{
	public:
	string type(int a, int b, int c)
	{
		int hyp = max(max(a, b), c);
		int leg1 = min(min(a, b), c);
		int leg2 = a+b+c-leg1-hyp;
		if(leg1+leg2<=hyp) return "IMPOSSIBLE";
		if(leg1*leg1 + leg2*leg2 ==hyp*hyp) return "RIGHT";
		else if(leg1*leg1 + leg2*leg2 < hyp*hyp) return "OBTUSE";
		else return "ACUTE";
	}
};
