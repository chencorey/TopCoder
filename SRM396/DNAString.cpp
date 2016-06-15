// https://community.topcoder.com/stat?c=problem_statement&pm=8584&rd=12168
// This problem was used for: 
// Single Round Match 396 Round 1 - Division I, Level One 
// Single Round Match 396 Round 1 - Division II, Level Two

#include <string>
#include <vector>
using namespace std;
class DNAString
{
	public:
	int minChanges(int maxPeriod, vector<string> dna)
	{
		string target = "";
		for(int i=0; i<dna.size(); i++)
		{
			target+=dna[i];
		}
		int result = 2500;
		for(int i=1; i<=maxPeriod; i++)
		{
			int changes = 0;
			for(int mod = 0; mod<i; mod++)
			{
				int j = mod;
				int counts[4];
				for(int k=0; k<4; k++)
				{
					counts[k] = 0;
				}
				while(j<target.length())
				{
					if(target[j]=='A')counts[0]++;
					if(target[j]=='C')counts[1]++;
					if(target[j]=='G')counts[2]++;
					if(target[j]=='T')counts[3]++;
					j+=i;
				}
				int max = 0;
				int numLetters = 0;
				for(int k=0; k<4; k++)
				{
					numLetters +=counts[k];
					if(counts[k]>max) max = counts[k];
				}
				changes+=numLetters-max;
			}
			if(changes<result)result = changes;
		}
		return result;
	}
};
