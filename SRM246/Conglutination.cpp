// https://community.topcoder.com/stat?c=problem_statement&pm=4562&rd=7221
// This problem was used for: 
// Single Round Match 246 Round 1 - Division II, Level Two

#include <string>
#include <algorithm>
using namespace std;
class Conglutination{
	public:
	string split(string conglutination, int expectation)
	{
		for(int i=1; i<conglutination.length(); i++)
		{
			if (i > 15)continue;
			long long A = stoll(conglutination.substr(0, i));
		long long B;
		try {
			B = stoll(conglutination.substr(i));
		}
		catch (exception ex) { continue; }
			if(A+B==expectation)
			{
				return "" + conglutination.substr(0, i) + "+" + conglutination.substr(i);
			}
		}
		return "";
	}
};
