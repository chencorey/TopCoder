// https://community.topcoder.com/stat?c=problem_statement&pm=9824&rd=12179
// This problem was used for: 
// Single Round Match 407 Round 1 - Division I, Level One 
// Single Round Match 407 Round 1 - Division II, Level Two

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class CorporationSalary
{
	public:
	vector<string> relations;
	long long salary[50];
	long long getSalary(int employee)
	{	
		if(salary[employee]!=-1) return salary[employee];
		long long result = 0;
		for(int i = 0; i<relations[employee].length(); i++)
		{
			if(relations[employee][i]=='Y')
			{
				result+=getSalary(i);
			}
		}
		salary[employee] = max((long long)1, result);
		return salary[employee];
	}
	long long totalSalary(vector<string> input)
	{
		relations = input;
		for(int i = 0; i<input.size(); i++)
		{
			salary[i] = -1;
		}
		long long result = 0;
		for(int i = 0; i<input.size(); i++)
		{
			result+=getSalary(i);
		}
		return result;
	}
};
