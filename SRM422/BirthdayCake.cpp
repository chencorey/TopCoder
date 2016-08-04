// https://community.topcoder.com/stat?c=problem_statement&pm=10036&rd=13513
// This problem was used for: 
// Single Round Match 422 Round 1 - Division II, Level Three

#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;
class BirthdayCake
{
	public:
	int howManyFriends(vector<string> availableFruits, vector<string> friendsDislikings, int K)
	{
		vector<vector<int> > cannotEat;
		int result = 0;
		for(int i = 0; i<friendsDislikings.size(); i++)
		{
			stringstream ss;
			ss<<friendsDislikings[i];
			vector<int> dislikes;
			string s;
			while(ss>>s)
			{
				for(int j = 0; j<availableFruits.size(); j++)
				{
					if(s==availableFruits[j])
					{
						dislikes.push_back(j);
					}			
				}
			}
			cannotEat.push_back(dislikes);
		}
		for(int i = 0; i<(1<<friendsDislikings.size()); i++)
		{		
			bool goodFruits[50];
			for(int j = 0; j<50; j++)
			{
				goodFruits[j] = true;
			}
			int numPeople = 0;
			for(int j = 0; j<friendsDislikings.size(); j++)
			{
				if(i&(1<<j))
				{
					numPeople++;
					for(int k = 0; k<cannotEat[j].size(); k++)
					{
						goodFruits[cannotEat[j][k]] = false;
					}
				}
			}
			int numFruits = 0;
			for(int j = 0; j<availableFruits.size(); j++)
			{
				if(goodFruits[j]) numFruits++;
			}
			if(numFruits>=K)
			{
				result = max(result, numPeople);
			}
		}
		return result;
	}
};
