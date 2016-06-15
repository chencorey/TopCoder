// https://community.topcoder.com/stat?c=problem_statement&pm=4472&rd=7221
// This problem was used for: 
// Single Round Match 246 Round 1 - Division I, Level Two 
// Single Round Match 246 Round 1 - Division II, Level Three

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class CalcButton{
	public:
	string getDigits(vector<string> sequence)
	{
		string arr[2498];
		int counts[2498];
		int lastUpdated[2498];
		for(int i=0; i<2498; i++)
		{
			lastUpdated[i]=-4;
		}
		int curr = 0;
		string concat;
		for(int i=0; i<sequence.size(); i++)
		{
			concat+=sequence[i];
		}
		if(concat.length()<3) return "000";
		for(int i=0; i<concat.length()-2; i++)
		{
			string temp = concat.substr(i, 3);
			bool found = false;
			for(int j=0; j<curr; j++)
			{
				if(arr[j]==temp)
				{
					if(lastUpdated[j]<=i-3)
					{
						counts[j]++;
						lastUpdated[j] = i;
					}
					found = true;
				}
			}
			if(!found)
			{
				lastUpdated[curr]= i;
				arr[curr] = temp;
				counts[curr] = 1;
				curr++;
			}
		}
		vector<string> possibilities;
		int max = 0;
		for(int i=0; i<curr; i++)
		{
			if(counts[i]>max)
			{
				possibilities.clear();
				possibilities.push_back(arr[i]);
				max = counts[i];
			}
			else if(counts[i]==max)
			{
				possibilities.push_back(arr[i]);
			}
		}
		sort(possibilities.begin(), possibilities.end());
		return possibilities[0];
	}
};
