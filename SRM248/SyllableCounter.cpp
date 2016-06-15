// https://community.topcoder.com/stat?c=problem_statement&pm=3524&rd=7223
// This problem was used for: 
// Single Round Match 248 Round 1 - Division II, Level One

#include <string>
using namespace std;
class SyllableCounter
{
	public:
	int countSyllables(string input)
	{
		int count = 0;
		bool inGroup = false;
		for(int i=0; i<input.length(); i++)
		{
			if(input[i]=='A'||input[i]=='E'||input[i]=='I'||input[i]=='O'||input[i]=='U')
			{
				if(!inGroup)
				{
					inGroup = true;
					count++;
				}
			}
			else
			{
				inGroup = false;
			}
		}
		return count;
	}
};
