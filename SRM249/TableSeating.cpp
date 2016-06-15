// https://community.topcoder.com/stat?c=problem_statement&pm=4616&rd=7224
// This problem was used for: 
// Single Round Match 249 Round 1 - Division I, Level One 
// Single Round Match 249 Round 1 - Division II, Level Three

#include <vector>
#include <cmath>
using namespace std;
class TableSeating
{
	public:
	double getExpected(int numTables, vector<int> probs)
	{
		vector<double> eValue;
	for(int i=0; i<pow(2, numTables); i++)
	{
		eValue.push_back(0);
	}
	for(int i=pow(2, numTables)-1; i>=0; i--)
	{
		int itemp = i;
		vector<bool> taken;
		for(int j=0; j<numTables; j++)
		{
			taken.push_back(itemp%2==1);
			if(itemp%2==1) eValue[i]++;
			itemp/=2;
		}
		double eV = 0;
		for(int j=0; j<probs.size(); j++)
		{
			vector<int> valuesToAdd;
			for(int k=0; k<numTables-j; k++)
			{
				bool possible = true;
				for(int l=k; l<k+j+1; l++)
				{
					if(taken[l])
					{
						possible = false;
						break;
					}
				}
				if(possible)
				{
					int valueToAdd = 0;
					for(int l=k; l<k+j+1; l++)
					{
						valueToAdd+=pow(2, l);
					}
					valuesToAdd.push_back(valueToAdd);
					//eValue[i]+=((double)(probs[j]))/100 * eValue[i+valueToAdd];
				}
			}
			for(int k=0; k<valuesToAdd.size(); k++)
			{
				eV+=((double)(probs[j]))/100 * (eValue[i+valuesToAdd[k]]-eValue[i]) / valuesToAdd.size();
			}
		}
		eValue[i] += eV;
	}
	return eValue[0];
	}
};
