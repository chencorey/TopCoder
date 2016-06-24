// https://community.topcoder.com/stat?c=problem_statement&pm=8760&rd=12171
// This problem was used for: 
// Single Round Match 399 Round 1 - Division II, Level Two

using namespace std;
class MaximalProduct
{
	public:
	long long maximalProduct(int s, int k)
	{
		long long product = 1;
		while(k>0)
		{
			product *= (s+k-1)/k;
			s = s-(s+k-1)/k;
			k--;
		}
		return product;
	}
};
