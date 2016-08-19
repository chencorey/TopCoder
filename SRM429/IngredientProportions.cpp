// https://community.topcoder.com/stat?c=problem_statement&pm=8729&rd=13520
// This problem was used for: 
// Single Round Match 429 Round 1 - Division I, Level Two 
// Single Round Match 429 Round 1 - Division II, Level Three

#include <vector>
#include <string>
using namespace std;
class IngredientProportions
{
	public:
	int gcd(int a, int b)
	{
		while(a!=0&&b!=0)
		{
			int c = min(a, b);
			a = max(a,b)%c;
			b = c;
		}
		return max(a, b);
	}
	int lcm(int a, int b)
	{
		return a*b/gcd(a, b);
	}
	vector<int> getMasses(vector<string> proportions)
	{
		vector<int> ing;
		for(int i =0; i<=proportions.size(); i++)
		{
			ing.push_back(1);
		}
		for(int i = 0; i<proportions.size(); i++)
		{
			int a = stoi(proportions[i].substr(1, 1));
			int b = stoi(proportions[i].substr(8, 1));
			int c = stoi(proportions[i].substr(13, 1));
			int d = stoi(proportions[i].substr(15, 1));
			int gcdp = gcd(c, d);
			c = c/gcdp;
			d = d/gcdp;
			ing[a] = lcm(ing[a], c);
			ing[b] = lcm(ing[b], d);
		}
		bool change = true;
		while(change)
		{
			change = false;
			for(int i = 0; i<proportions.size(); i++)
			{
				int a = stoi(proportions[i].substr(1, 1));
				int b = stoi(proportions[i].substr(8, 1));
				int c = stoi(proportions[i].substr(13, 1));
				int d = stoi(proportions[i].substr(15, 1));
				int gcdp = gcd(c, d);
				c = c/gcdp;
				d = d/gcdp;
				int preva = ing[a];
				int prevb = ing[b];
				int diffa = ing[a]/c;
				int diffb = ing[b]/d;
				int gcddiff = gcd(diffa, diffb);
				ing[a] = ing[a]*(diffb/gcddiff);
				ing[b] = ing[b]*(diffa/gcddiff);
				if(preva!=ing[a]||prevb!=ing[b])
				{
					change= true;
				}
			}
		}
		return ing;
	}
};
