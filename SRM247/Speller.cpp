// https://community.topcoder.com/stat?c=problem_statement&pm=4521&rd=7222
// This problem was used for: 
// Single Round Match 247 Round 1 - Division II, Level Three

#include <string>
#include <vector>
using namespace std;
class Speller{
	public:
	int value(string number)
	{
		string tens[8] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
		vector<string> allNumbers;
		allNumbers.push_back("one");
		allNumbers.push_back("two");
		allNumbers.push_back("three");
		allNumbers.push_back("four");
		allNumbers.push_back("five");
		allNumbers.push_back("six");
		allNumbers.push_back("seven");
		allNumbers.push_back("eight");
		allNumbers.push_back("nine");
		allNumbers.push_back("ten");
		allNumbers.push_back("eleven");
		allNumbers.push_back("twelve");
		allNumbers.push_back("thirteen");
		allNumbers.push_back("fourteen");
		allNumbers.push_back("fifteen");
		allNumbers.push_back("sixteen");
		allNumbers.push_back("seventeen");
		allNumbers.push_back("eighteen");
		allNumbers.push_back("nineteen");
		for(int i=2; i<10; i++)
		{
			for(int j=0; j<10; j++)
			{
				if(j==0) allNumbers.push_back(tens[i-2]);
				else allNumbers.push_back(tens[i-2]+"-"+allNumbers[j-1]);
			}
		}
		int distance[99];
		for(int i=0; i<99; i++)
		{
			if(allNumbers[i].length()!=number.length())
			{
				distance[i]=21;
			}
			else
			{
				int counter = 0;
				for(int j=0;j<number.length(); j++)
				{
					if(allNumbers[i][j]!=number[j])
					{
						counter++;
					}
				}
				distance[i] = counter;
			}
		}
		int min = 21;
		int result;
		for(int i=0; i<99; i++)
		{
			if(distance[i]<min)
			{
				result = i+1;
				min = distance[i];
			}
			else if(distance[i]==min)
			{
				result = -1;
			}
		}
		return result;
	}
};
