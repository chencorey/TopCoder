// https://community.topcoder.com/stat?c=problem_statement&pm=9895&rd=13505
// This problem was used for: 
// Single Round Match 414 Round 1 - Division I, Level One 
// Single Round Match 414 Round 1 - Division II, Level Two

#include <vector>
#include <algorithm>
using namespace std;
class Embassy
{
	public:
	int visaApplication(vector<int> forms, int dayLength, int openTime)
	{
		int minTime = 1000000000;
		//i is the form that was approved right when embassy opened
		for(int i = 0; i<forms.size(); i++)
		{
			int startTime = -forms[i];
			for(int j = i-1; j>=0; j--)
			{
				if((startTime+dayLength*100)%dayLength>openTime)
				{
					startTime-=((startTime+dayLength*100)%dayLength-openTime);
				}
				startTime-=forms[j];
			}
			//work forwards from i
			int endTime = 0;
			for(int j = i+1; j<forms.size(); j++)
			{
				endTime+=forms[j];
				if((endTime%dayLength)>openTime)
				{
					endTime+=(dayLength-(endTime%dayLength));
				}
			}
			minTime = min(minTime, endTime-startTime);
		}
		return minTime;
	}
};
