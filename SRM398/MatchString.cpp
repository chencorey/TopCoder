// https://community.topcoder.com/stat?c=problem_statement&pm=8160&rd=12170
// This problem was used for: 
// Single Round Match 398 Round 1 - Division II, Level Three

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
class MatchString
{
	public:
	int placeWords(string matchString, vector<string> matchWords)
	{
		int matchColumnShifts[50];
		for(int i = 0; i<50; i++)
		{
			matchColumnShifts[i] = 0;
		}
		for(int i = 0; i<50; i++)
		{
			for(int j = 0; j<matchString.length(); j++)
			{
				int dist = 100;
				bool found = false;
				for(int k = 0; k<matchWords[j].length(); k++)
				{
					if(matchWords[j][k]==matchString[j])
					{
						if(abs(k-i)<dist)
						{
							found = true;
							if(k<=i)
							{
								dist = abs(k-i);
							}
						}
					}
				}
				if(!found)
				{
					return -1;
				}
				else
				{
					if(dist<100)
						matchColumnShifts[i]+=dist;
					else
						matchColumnShifts[i]+=2500;
				}
			}
		}
		int result = 2500;
		for(int i = 0; i<50; i++)
		{
			if(matchColumnShifts[i]<result)result = matchColumnShifts[i]; 
		}
		return result;
	}
};
