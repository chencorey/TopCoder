// https://community.topcoder.com/stat?c=problem_statement&pm=9828&rd=12181
// This problem was used for: 
// Single Round Match 409 Round 1 - Division I, Level Two


#include <algorithm>
#include <vector>
using namespace std;
class MagicalSpheres
{
	public:
	int exponent(int p, int n)
	{
		int res =0;
		int q=p;
		while(q<=n)
		{
			res+=n/q;
			if(n/p<q) break;
			q*=p;
		}
		return res;
	}
	vector<int> getPrimes(int k)
	{
		int divisor = 2;
		vector<int> result;
		while(divisor*divisor<=k)
		{
			if(k%divisor==0)
			{
				result.push_back(divisor);
				k/=divisor;
			}
			else
			{
				divisor++;
			}
		}
		if(k!=1&&k<=100000) result.push_back(k);
		return result;
	}
	int divideWork(int reals, int fakes, int gnomes)
	{
		int result = 1;
		for(int i = 2; i<=gnomes; i++)
		{
			bool works = true;
			vector<int> primes = getPrimes(i);
			int last = -1;
			int count = 0;
			for(int j = 0; j<primes.size(); j++)
			{
				if(primes[j]!=last&&last!=-1)
				{
					if(exponent(last, reals+fakes)-exponent(last, reals)-exponent(last, fakes)<count)
					{
						works = false;
						break;
					}
					count = 1;
				}
				else
				{
					count++;
				}
				last = primes[j];
			}
			if(count>0)
			{
				if(exponent(last, reals+fakes)-exponent(last, reals)-exponent(last, fakes)<count)
				{
					works = false;
				}
			}
			if(works) result = i;
		}
		return result;		
	}
};
