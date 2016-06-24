// https://community.topcoder.com/stat?c=problem_statement&pm=8758&rd=12171
// This problem was used for: 
// Single Round Match 399 Round 1 - Division I, Level One 
// Single Round Match 399 Round 1 - Division II, Level Three

#include <vector>
#include <algorithm>
using namespace std;
class AvoidingProduct
{
	public:
	vector<int> getTriple(vector<int> a, int n)
	{
		int min = 1000000;
		vector<int> result;
		for(int i = 1; i<100; i++)
		{
			bool canUse = true;
			for(int t = 0; t<a.size(); t++)
			{
				if(i ==a[t])
				{
					canUse = false;
					break;
				}
			}
			if(!canUse) continue;
			for(int j = i; j<100; j++)
			{
				bool canUse2 = true;
				for(int t = 0; t<a.size(); t++)
				{
					if(j ==a[t])
					{
						canUse2 = false;
						break;
					}
				}
				if(!canUse2) continue;
				for(int k = 1; k<1030; k++)
				{
					bool canUse3 = true;
					for(int t = 0; t<a.size(); t++)
					{
						if(k ==a[t])
						{
							canUse3 = false;
							break;
						}
					}
					if(!canUse3) continue;
					if(abs(n-i*j*k)<min)
					{
						result.clear();
						min = abs(n-i*j*k);
						result.push_back(i);
						result.push_back(j);
						result.push_back(k);
					}
				}
			}
		}
		return result;
	}
};
