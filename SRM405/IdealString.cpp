// https://community.topcoder.com/stat?c=problem_statement&pm=9757&rd=12177
// This problem was used for: 
// Single Round Match 405 Round 1 - Division II, Level Three

#include <string>
#include <queue>
using namespace std;
class IdealString
{
	public:
	int dp[101][101];
	int length;
	bool can(int len, int remaining)
	{
		if(remaining<0) return false;
		if(len+remaining>length) return false;
		if(len==length) return remaining==0;
		if(dp[len][remaining]==-1)
		{
			if(can(len+1, remaining+len)||can(len+1, remaining-1))
			{
				dp[len][remaining]=1;
				return true;
			}
			else
			{
				dp[len][remaining]=0;
				return false;
			}
		}
		else
		{
			return dp[len][remaining]==1;
		}
	
	}
	string construct(int n)
	{
		length = n;
		for(int i = 0; i<=n; i++)
		{
			for(int j = 0; j<=n; j++)
			{
				dp[i][j] = -1;
			}
		}
		string result = "";
		queue<char> letters;
		char curr = 'A';
		while(result.length()<n)
		{
			if(can(result.length()+1, letters.size()-1))
			{
				result+=letters.front();
				letters.pop();
			}
			else if(can(result.length()+1, letters.size()+result.length()))
			{
				for(int i = 0; i<result.length(); i++)
				{
					letters.push(curr);
				}
				result+=curr;
				curr++;
			}
			else
			{
				return "";
			}
		}
		return result;
	}
};
