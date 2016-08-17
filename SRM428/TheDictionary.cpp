// https://community.topcoder.com/stat?c=problem_statement&pm=10183&rd=13519
// This problem was used for: 
// Single Round Match 428 Round 1 - Division II, Level Three

#include <string>
#include <algorithm>
using namespace std;
class TheDictionary
{
	public:
	int C[201][201];
	string go(int n, int m, int k)
	{
		if(n==0||m==0)
		{
			string build;
			for(int i = 0 ; i<max(n, m); i++)
			{
				build+=(m>n)?'z':'a';
			}
			return build;
		}
		if(k>C[n+m-1][n-1])
		{
			return "z"+go(n, m-1, k-C[n+m-1][n-1]);
		}
		else return "a"+go(n-1, m, k);
	}
	string find(int n, int m, int k)
	{
		for(int i = 0; i<201; i++)
		{
			C[i][0] = 1;
			C[i][i] = 1;
			for(int j = 1; j<i; j++)
			{
				C[i][j] = min(C[i-1][j-1]+C[i-1][j], 1000000001);
			}
		}
		if(k>C[n+m][m]) return "";
		return go(n, m, k);
	}
};
