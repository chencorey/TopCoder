// https://community.topcoder.com/stat?c=problem_statement&pm=8427&rd=12178
// This problem was used for: 
// Single Round Match 406 Round 1 - Division II, Level Two

#include <vector>
using namespace std;
class FactoVisors
{
	public:
	long long GCD(long long a, long long b)
	{
		if (b==0) return a;
		return GCD(b,a%b);
	}
	long long LCM(long long a, long long b)
	{
		return b*a/GCD(a,b);
	}
	int getNum(vector<int> divisors, vector<int> multiples)
	{
		int gcd = multiples[0];
		int lcm = divisors[0];
		for(int i = 1; i<multiples.size(); i++)
		{
			gcd = GCD(gcd, multiples[i]);
		}
		for(int i = 1; i<divisors.size(); i++)
		{
			lcm = LCM(lcm, divisors[i]);
		}
		if(gcd%lcm!=0) return 0;
		vector<int> primeCount;
		int target = gcd/lcm;
		int curr = 2;
		int count = 0;
		while(target!=1&&curr<10000000&&curr<gcd)
		{
			if(target%curr==0)
			{
				count++;
				target = target/curr;
			}
			else
			{
				if(count!=0) primeCount.push_back(count);
				count = 0;
				curr++;
			}
		}
		if(count!=0) primeCount.push_back(count);
		int total = 1;
		for(int i = 0; i<primeCount.size(); i++)
		{
			total*=(primeCount[i]+1);
		}
		if(target!=1) total++;
		return total;
	}
};
