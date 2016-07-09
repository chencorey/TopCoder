// https://community.topcoder.com/stat?c=problem_statement&pm=9823&rd=12181
// This problem was used for: 
// Single Round Match 409 Round 1 - Division I, Level One 
// Single Round Match 409 Round 1 - Division II, Level Two

#include <vector>
#include <string>
using namespace std;
class OrderedSuperString
{
	public:
	int getLength(vector<string> words)
	{
		int lastStartIndex = 0;
		string super = words[0];
		for(int i = 1; i<words.size(); i++)
		{
			for(int j = lastStartIndex; j<super.length(); j++)
			{
				bool works = true;
				for(int k = j; k<super.length()&&k-j<words[i].length(); k++)
				{
					if(words[i][k-j]!=super[k])
					{
						works = false;
						break;
					}
				}
				if(works)
				{
					if(words[i].length()>super.length()-j)
					super+=words[i].substr(super.length()-j);
					lastStartIndex = j;
					break;
				}
				if(!works&&j==super.length()-1)
				{
					lastStartIndex = j+1;
					super+=words[i];
				}
			}
		}
		return super.length();
	}
};
