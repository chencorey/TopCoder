// https://community.topcoder.com/stat?c=problem_statement&pm=4670&rd=8006
// This problem was used for: 
// Single Round Match 254 Round 1 - Division II, Level Two

#include <string>
using namespace std;
class ListeningIn
{
	public:
	string probableMatch(string a, string b)
	{
		string result = "";
		int index = 0;
		for(int i=0; i<b.length(); i++)
		{
			if(index==a.length())
			{
				result+=b[i];
				continue;
			}
			if(b[i]==a[index])
			{
				index++;
			}
			else
			{
				result +=b[i];
			}
		}
		if(index!=a.length())return "UNMATCHED";
		return result;
	}
};
