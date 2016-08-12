// https://www.topcoder.com/stat?c=problem_statement&pm=10155&rd=13518
// This problem was used for: 
// Single Round Match 427 Round 1 - Division I, Level One 
// Single Round Match 427 Round 1 - Division II, Level Two
class DesignCalendar
{
	public:
	int shortestPeriod(int dayLength, int yearLength)
	{
		int d = dayLength;
		int y = yearLength;
		while(d>0)
		{
			int c = d;
			d=y%d;
			y = c;
		}
		return dayLength/y;
	}
};
