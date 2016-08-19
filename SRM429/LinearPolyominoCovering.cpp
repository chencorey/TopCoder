// https://community.topcoder.com/stat?c=problem_statement&pm=10251&rd=13520
// This problem was used for: 
// Single Round Match 429 Round 1 - Division II, Level One

#include <string>
using namespace std;
class LinearPolyominoCovering
{
	public:
	string findCovering(string region)
	{
		int xCount = 0;
		string result;
		for(int i = 0; i<region.length(); i++)
		{
			if(region[i]=='.')
			{
				if(xCount!=0)
				{
					if(xCount==2)
					{
						result+="BB";
						xCount=0;
					}
					else return "impossible";
				}
				result+=".";
			}
			else
			{
				xCount++;
				if(xCount==4)
				{
					xCount=0;
					result+="AAAA";
				}
			}			
		}
		if(xCount!=0)
		{
			if(xCount==2)
			{
				result+="BB";
			}
			else return "impossible";
		}
		return result;
	}
};
