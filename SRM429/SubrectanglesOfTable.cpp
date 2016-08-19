// https://community.topcoder.com/stat?c=problem_statement&pm=10246&rd=13520
// This problem was used for: 
// Single Round Match 429 Round 1 - Division I, Level One 
// Single Round Match 429 Round 1 - Division II, Level Two

#include <vector>
#include <string>
using namespace std;
class SubrectanglesOfTable
{
	public:
	vector<long long> getQuantity(vector<string> table)
	{
		vector<long long> result;
		for(int i =0; i<26; i++)
		{
			result.push_back(0);
		}
		// 1
		for(int i = 0; i<table.size(); i++)
		{
			for(int j = 0; j<table[i].length(); j++)
			{
				long long amt = (long long)(i+1)*(2*table.size()-i)*(j+1)*(2*table[i].length()-j);
				result[table[i][j]-'A']+=amt;
			}
		}
		// 2
		for(int i =0; i<table.size()/2; i++)
		{
			string temp = table[i];
			table[i] = table[table.size()-i-1];
			table[table.size()-i-1] = temp;
		}
		for(int i = 0; i<table.size(); i++)
		{
			for(int j = 0; j<table[i].length(); j++)
			{
				long long amt = (long long)(i+1)*(2*table.size()-i)*(j+1)*(2*table[i].length()-j);
				result[table[i][j]-'A']+=amt;
			}
		}
		// 3
		for(int i = 0; i<table.size(); i++)
		{
			for(int j = 0; j<table[i].length()/2; j++)
			{
				char temp = table[i][j];
				table[i][j] = table[i][table[i].length()-j-1];
				table[i][table[i].length()-j-1] = temp;
			}
		}
		for(int i = 0; i<table.size(); i++)
		{
			for(int j = 0; j<table[i].length(); j++)
			{
				long long amt = (long long)(i+1)*(2*table.size()-i)*(j+1)*(2*table[i].length()-j);
				result[table[i][j]-'A']+=amt;
			}
		}
		// 4
		for(int i =0; i<table.size()/2; i++)
		{
			string temp = table[i];
			table[i] = table[table.size()-i-1];
			table[table.size()-i-1] = temp;
		}
		for(int i = 0; i<table.size(); i++)
		{
			for(int j = 0; j<table[i].length(); j++)
			{
				long long amt = (long long)(i+1)*(2*table.size()-i)*(j+1)*(2*table[i].length()-j);
				result[table[i][j]-'A']+=amt;
			}
		}
		return result;
	}
};
