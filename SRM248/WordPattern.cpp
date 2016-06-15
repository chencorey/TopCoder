// https://community.topcoder.com/stat?c=problem_statement&pm=3523&rd=7223
// This problem was used for: 
// Single Round Match 248 Round 1 - Division I, Level One 
// Single Round Match 248 Round 1 - Division II, Level Two

#include <cmath>
#include <string>
using namespace std;
class WordPattern
{
	public:
	long long countWords(string ori)
	{
		if(ori.length()==1)return 1;
		return pow((long long)2, (long long)ori.length()+1)-4;
	}
};
