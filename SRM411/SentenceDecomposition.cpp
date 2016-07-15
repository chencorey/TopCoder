// https://community.topcoder.com/stat?c=problem_statement&pm=8692&rd=12183
// This problem was used for: 
// Single Round Match 411 Round 1 - Division I, Level One 
// Single Round Match 411 Round 1 - Division II, Level Two

#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class SentenceDecomposition
{
	public:
	vector<string> words;
	int canForm(string chars)
	{
		int result = 100;
		for(int i = 0; i<words.size(); i++)
		{
			if(words[i].length()==chars.length())
			{
				string sword = words[i];
				string schars = chars;
				sort(sword.begin(), sword.end());
				sort(schars.begin(), schars.end());
				if(sword==schars)
				{
					int count = 0;
					for(int j = 0; j<chars.length(); j++)
					{
						if(chars[j]!=words[i][j])
						{
							count++;
						}
					}
					result = min(result, count);
				}
			}
		}
		return result;
	}
	int decompose(string sentence, vector<string> validWords)
	{
		words = validWords;
		int dp[51];
		for(int i = 0; i<50; i++)
		{
			dp[i] = 100;
		}
		dp[sentence.length()] = 0;
		for(int i = sentence.length()-1; i>=0; i--)
		{
			for(int j = i+1; j<=sentence.length(); j++)
			{
				int added = canForm(sentence.substr(i, j-i));
				dp[i] = min(dp[i], dp[j]+added);
			}
		}
		if(dp[0] ==100) return -1;
		return dp[0];
	}
};
