// https://community.topcoder.com/stat?c=problem_statement&pm=10182&rd=13519
// This problem was used for: 
// Single Round Match 428 Round 1 - Division II, Level One

#include <string>
using namespace std;
class ThePalindrome
{
	public:
	int find(string s)
	{
		for(int i = 0; i<s.length()-1; i++)
		{
			string check = s.substr(i);
			int low = 0, high = check.length()-1;
			bool isP = true;
			while(low<high)
			{
				if(check[low]!=check[high])
				{
					isP = false;
					break;
				}
				low++;
				high--;
			}
			if(isP) return 2*s.length()-check.length();
		}
		return 2*s.length()-1;
	}
};
