// https://community.topcoder.com/stat?c=problem_statement&pm=8310&rd=12174
// This problem was used for: 
// Single Round Match 402 Round 1 - Division II, Level One

#include <vector>
#include <string>
using namespace std;
class WordAbbreviation
{
	public:
	vector<string> getAbbreviations(vector<string> input)
	{
		vector<string> output;
		for(int i = 0; i<input.size(); i++)
		{
			for(int j = 1; j<=input[i].length(); j++)
			{
				bool works = true;
				for(int k = 0; k<input.size(); k++)
				{
					if(k==i) continue;
					if(input[i].substr(0, j)==input[k].substr(0, j))
					{
						works = false;
						break;
					}
				}
				if(works)
				{
					output.push_back(input[i].substr(0, j));
					break;
				}
			}
		}

		return output;
	}
};
