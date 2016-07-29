// https://community.topcoder.com/stat?c=problem_statement&pm=9871&rd=13512
// This problem was used for: 
// Single Round Match 421 Round 1 - Division II, Level Three

#include <vector>
#include <string>
#include <cmath>
using namespace std;
class FloorIndicator
{
	public:
	string arr[10][5] = {{"###","#.#","#.#","#.#","###"},
		{"..#","..#","..#","..#","..#"},
		{"###","..#","###","#..","###"},
		{"###","..#","###","..#","###"},
		{"#.#","#.#","###","..#","..#"},
		{"###","#..","###","..#","###"},
		{"###","#..","###","#.#","###"},
		{"###","..#","..#","..#","..#"},
		{"###","#.#","###","#.#","###"},
		{"###","#.#","###","..#","###"}};
	double averageDigit(vector<string> digit)
	{
		double sum = 0;
		double count = 0;
		for(int i = 0; i<=9; i++)
		{
			bool works = true;
			for(int j = 0; j<5; j++)
			{
				for(int k = 0; k<3; k++)
				{
					if(digit[j][k]=='#'&&arr[i][j][k]=='.')
					{
						works = false;
					}
				}
			}
			if(works)
			{
				sum+=i;
				count++;
			}
		}
		if(count==0) return -1;
		return sum/count;
	}
	double averageFloor(int N, vector<string> indicator)
	{
		double result = 0;
		for(int i = 0; i<N; i++)
		{
			vector<string> digit;
			for(int j = 0; j<5; j++)
			{
				digit.push_back(indicator[j].substr(4*i, 3));
			}
			double avg = averageDigit(digit);
			if(avg==-1) return -1;
			result+=pow(10, N-i-1)*avg;
		}
		return result;
	}
};
