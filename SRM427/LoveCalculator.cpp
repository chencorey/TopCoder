// https://community.topcoder.com/stat?c=problem_statement&pm=10046&rd=13518
// This problem was used for: 
// Single Round Match 427 Round 1 - Division II, Level One

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class LoveCalculator
{
	public:
	string findBoy(string girl, vector<string> boys)
	{
		int arr[4];
		for(int i = 0; i<4; i++)
		{
			arr[i] = 0;
		}
		sort(boys.begin(), boys.end());
		for(int i = 0; i<girl.length(); i++)
		{
			if(girl[i]=='L')arr[0]++;
			if(girl[i]=='O')arr[1]++;
			if(girl[i]=='V')arr[2]++;
			if(girl[i]=='E')arr[3]++;
		}
		string result;
		int best = -1;
		for(int i = 0; i<boys.size(); i++)
		{
			int a[4];
			for(int j = 0; j<4; j++)
			{
				a[j] = 0;
			}
			for(int j = 0; j<boys[i].length(); j++)
			{
				if(boys[i][j]=='L')a[0]++;
				if(boys[i][j]=='O')a[1]++;
				if(boys[i][j]=='V')a[2]++;
				if(boys[i][j]=='E')a[3]++;
			}
			int calc = ((a[0]+arr[0]+a[1]+arr[1])*(a[0]+arr[0]+a[2]+arr[2])*(a[0]+arr[0]+a[3]+arr[3])*
			(a[1]+arr[1]+a[2]+arr[2])*(a[1]+arr[1]+a[3]+arr[3])*(a[2]+arr[2]+a[3]+arr[3]))%100;
			if(calc>best)
			{
				result = boys[i];
				best = calc;
			}
		}
		return result;
	}
};
