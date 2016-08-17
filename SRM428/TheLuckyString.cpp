// https://community.topcoder.com/stat?c=problem_statement&pm=10180&rd=13519
// This problem was used for: 
// Single Round Match 428 Round 1 - Division I, Level One 
// Single Round Match 428 Round 1 - Division II, Level Two

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class TheLuckyString
{
	public:
	int result;
	int letters[26];
	int L;
	void go(int pos, char prev)
	{
		if(pos==L)
		{
			result++;
			return;
		}
		for(int i = 0; i<26; i++)
		{
			if(letters[i]>0&&i!=prev-'a')
			{
				letters[i]--;
				go(pos+1, i+'a');
				letters[i]++;
			}
		}
	}
	int count(string s)
	{
		L = s.length();
		for(int i = 0; i<s.length(); i++)
		{
			letters[s[i]-'a']++;
		}
		go(0, 'A');
		return result;
	}
};
