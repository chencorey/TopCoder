// https://community.topcoder.com/stat?c=problem_statement&pm=4613&rd=7224
// This problem was used for: 
// Single Round Match 249 Round 1 - Division II, Level One

#include <string>
#include <vector>
using namespace std;
class ChatTranscript
{
	public:
	int howMany(vector<string> transcript, string name)
	{
		int result = 0;
		name = name+":";
		for(int i=0; i<transcript.size(); i++)
		{
			if(name.length()<=transcript[i].length())
			{
				result++;
				for(int j=0; j<name.length(); j++)
				{
					if(name[j]!=transcript[i][j])
					{
						result--;
						break;
					}
				}
			}
		}
		return result;
	}
};
