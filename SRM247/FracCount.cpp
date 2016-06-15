// https://community.topcoder.com/stat?c=problem_statement&pm=4522&rd=7222
// This problem was used for: 
// Single Round Match 247 Round 1 - Division II, Level Two

using namespace std;
class FracCount
{
	public:
	int position(int numerator, int denominator)
	{
		int count = 0;
		for(int i=2; i<=denominator; i++)
		{
			for(int j=1; j<i; j++)
			{
				bool relprime = true;
				for(int k=2; k<=j; k++)
				{
					if(i%k==0&&j%k==0)
					{
						relprime = false;
						break;
					}
				}
				if(relprime) count++;
				if(j==numerator && i==denominator) return count;
			}
		}
		return -1;
	}
};
