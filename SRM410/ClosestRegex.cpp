// https://community.topcoder.com/stat?c=problem_statement&pm=9727&rd=12182
// This problem was used for: 
// Single Round Match 410 Round 1 - Division II, Level Three

#include <string>
using namespace std;
class ClosestRegex
{
	public:
	string closestString(string text, string regex)
	{
		bool isStar[50];
		int dp[51][51];
		string matches[51][51];
		string reg;
		int numStars = 0;
		for(int i = 0; i<50; i++)
		{
			isStar[i] = false;
			for(int j = 0; j<50; j++)
			{
				dp[i][j] = 10000;
			}
		}
		for(int i = 0; i<regex.length(); i++)
		{
			if(regex[i]=='*')
			{
				isStar[reg.length()-1] = true;
				numStars++;
			}
			else
			{
				reg+=regex[i];
			}
		}
		if(reg==regex&&regex.length()!=text.length()) return "";
		if(reg.length()-numStars>text.length())return "";
		dp[text.length()][reg.length()] = 0;
		for(int i = 0; i<text.length(); i++)
		{
			dp[i][reg.length()] = 1000;
		}
		for(int i = reg.length()-1; i>=0; i--)
		{
			if(isStar[i])
			{
				dp[text.length()][i]=dp[text.length()][i+1];
			}
			else
			{
				dp[text.length()][i] = 1000;
			}
		}
		for(int i = text.length()-1; i>=0; i--)
		{
			for(int j = reg.length()-1; j>=0; j--)
			{
				if(isStar[j])
				{
					if((dp[i+1][j]+(int)(text[i]!=reg[j]))<dp[i][j+1])
					{
						dp[i][j] = dp[i+1][j] + (int)(text[i]!=reg[j]);
						matches[i][j] = reg[j] + matches[i+1][j];
					}
					else if((dp[i+1][j]+(int)(text[i]!=reg[j]))>dp[i][j+1])
					{
						dp[i][j] = dp[i][j+1];
						matches[i][j] = matches[i][j+1];
					}
					else
					{
						if(reg[j] + matches[i+1][j]<matches[i][j+1])
						{
							dp[i][j] = dp[i+1][j] + (int)(text[i]!=reg[j]);
							matches[i][j] = reg[j] + matches[i+1][j];
						}
						else
						{
							dp[i][j] = dp[i][j+1];
							matches[i][j] = matches[i][j+1];
						}
					}
				}
				else
				{
					dp[i][j] = dp[i+1][j+1]+(int)(text[i]!=reg[j]);
					matches[i][j] = reg[j] + matches[i+1][j+1];
				}
			}
		}
		return matches[0][0];
	}
};
