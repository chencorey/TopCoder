// https://community.topcoder.com/stat?c=problem_statement&pm=8743&rd=12169
// This problem was used for: 
// Single Round Match 397 Round 1 - Division II, Level One

#include <string>
using namespace std;
class BreakingTheCode
{
	public:
	string decodingEncoding(string key, string input)
	{
		string result;
		if(input[0]>='a'&&input[0]<='z')
		{
			for(int i = 0; i<input.size(); i++)
			{
				for(int j = 0; j<key.size(); j++)
				{
					if(input[i]==key[j])
					{
						if(j+1<10)
						{
							result+="0"+to_string(j+1);
						}
						else
						{
							result+=to_string(j+1);
						}
					}
				}
			}
			return result;
		}
		else
		{
			for(int i = 0; i<input.size()/2; i++)
			{
				int index = stoi(input.substr(2*i, 2))-1;
				result+=key[index];
			}
			return result;
		}
	}
};
