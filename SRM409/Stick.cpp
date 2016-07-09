// https://community.topcoder.com/stat?c=problem_statement&pm=9810&rd=12181
// This problem was used for: 
// Single Round Match 409 Round 1 - Division II, Level One

class Stick
{
	public:
	int pieces(int x)
	{
		int count = 0;
		for(int i = 0; i<7; i++)
		{
			if((x&(1<<i))!=0) count++;
		}
		return count;
	}
};
