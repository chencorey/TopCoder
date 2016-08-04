// https://community.topcoder.com/stat?c=problem_statement&pm=10072&rd=13513
// This problem was used for: 
// Single Round Match 422 Round 1 - Division II, Level One

#include <string>
using namespace std;
class MultiNumber
{
	public:
	string check(int number)
	{
		string ns = to_string(number);
		for(int i = 1; i<ns.length(); i++)
		{
			int pre = 1;
			int suff = 1;
			for(int j = 0; j<ns.length(); j++)
			{
				int a = stoi(ns.substr(j, 1));
				if(j<i)
				{					
					pre*=a;
				}
				else
				{
					suff*=a;
				}
			}
			if(pre==suff)
			{
				return "YES";
			}
		}
		return "NO";
	}
};
