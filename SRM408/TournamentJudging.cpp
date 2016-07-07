// https://community.topcoder.com/stat?c=problem_statement&pm=9822&rd=12180
// This problem was used for: 
// Single Round Match 408 Round 1 - Division II, Level One 
// TCHS Single Round Match 52 Round 1 - Division I, Level One

#include <vector>
using namespace std;
class TournamentJudging
{
	public:
	int getPoints(vector<int> rawScores, vector<int> conversionFactor)
	{
		int total = 0;
		for(int i = 0; i<rawScores.size(); i++)
		{
			total+=rawScores[i]/conversionFactor[i];
			int mod = rawScores[i]%conversionFactor[i];
			if((double)mod/conversionFactor[i]>=0.5) total++;
		}
		return total;
	}
};
