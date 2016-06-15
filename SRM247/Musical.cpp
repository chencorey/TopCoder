// https://community.topcoder.com/stat?c=problem_statement&pm=4495&rd=7222
// This problem was used for: 
// Single Round Match 247 Round 1 - Division I, Level One

#include <string>
#include <vector>
#include <cmath>
using namespace std;
class Musical
{
	public: 
	string loser(int n, double time)
	{
		while(time>=10) time = time-10;
		vector<double> chairs;
		for(int i=0; i<=n-1; i++)
		{
			chairs.push_back(((double)i)/((double)(n-1)));
		}
		vector<double> children;
		for(int i=n-1; i>=0; i--)
		{
			double value = ((double)i)/((double)n) + (time)/10;
			if(value>=1) value--;
			children.push_back(value);
		}
		vector<double> distanceToChair;
		vector<int> targetChair;
		for(int i=0; i<n; i++)
		{
			double min = 1;
			int ind=-1;
			for(int j=0; j<n; j++)
			{
				double dist = abs(children[i]-chairs[j]);
				if(dist<min)
				{
					min = dist;
					ind = j;
				}
			}
			targetChair.push_back(ind);
			distanceToChair.push_back(min);			
		}
		int index = -1;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<i; j++)
			{
				if(abs(targetChair[i]-targetChair[j])%(n-1)==0)
				{
					if(distanceToChair[i]<distanceToChair[j])
					{
						index = j;
					}
					else
					{
						index = i;
					}
				}
			}
		}
		char result = 'A'+(index+n+1)%n;
		string r = "Q";
		r[0] = result;
		return r;
	}
};
