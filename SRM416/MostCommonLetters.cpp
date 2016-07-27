// https://community.topcoder.com/stat?c=problem_statement&pm=9905&rd=13507
// This problem was used for: 
// Single Round Match 416 Round 1 - Division II, Level One

#include <vector>
#include <string>
using namespace std;
class MostCommonLetters
{
	public: 
	string listMostCommon(vector<string> text)
	{
		int arr[26];
		for(int i = 0; i<26; i++)
		{
			arr[i] = 0;
		}
		for(int i = 0; i<text.size(); i++)
		{
			for(int j = 0; j<text[i].length(); j++)
			{
				arr[text[i][j]-'a']++;
			}
		}
		string result = "";
		int most = -1;
		for(int i = 0; i<26; i++)
		{
			if(arr[i]==most)
			{
				result+=('a'+i);
			}
			else if(arr[i]>most)
			{
				result = "";
				result += ('a' + i);
				most = arr[i];
			}
		}
		return result;
	}
};
