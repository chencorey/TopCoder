// https://community.topcoder.com/stat?c=problem_statement&pm=10105&rd=13512
// This problem was used for: 
// Single Round Match 421 Round 1 - Division II, Level One

#include <algorithm>
using namespace std;
class GymTraining
{
	public:
	int trainingTime(int needToTrain, int minPulse, int maxPulse, int trainChange, int restChange)
	{
		if(trainChange>maxPulse-minPulse) return -1;
		int currPulse = minPulse;
		int i = 0;
		while(needToTrain>0)
		{
			if(currPulse+trainChange<=maxPulse)
			{
				needToTrain--;
				currPulse+=trainChange;
			}
			else
			{
				currPulse = max(minPulse, currPulse-restChange); 
			}
			i++;
		}
		return i;
	}
};
