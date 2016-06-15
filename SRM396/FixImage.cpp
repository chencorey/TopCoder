// https://community.topcoder.com/stat?c=problem_statement&pm=8615&rd=12168
// This problem was used for: 
// Single Round Match 396 Round 1 - Division I, Level Two

#include <string>
#include <vector>
using namespace std;
class FixImage
{
	public:
	vector<string> input;
	int comp[50][50];
	int ymax;
	int xmax;
	void spread(int c, int i, int j)
	{
		if(i>0)
		{
			if(input[i-1][j]=='#'&&comp[i-1][j]!=c)
			{
				comp[i-1][j] = c;
				spread(c, i-1, j);
			}
		}
		if(i<ymax-1)
		{
			if(input[i+1][j]=='#'&&comp[i+1][j]!=c)
			{
				comp[i+1][j] = c;
				spread(c, i+1, j);
			}
		}
		if(j>0)
		{
			if(input[i][j-1]=='#'&&comp[i][j-1]!=c)
			{
				comp[i][j-1] = c;
				spread(c, i, j-1);
			}
		}
		if(j<xmax-1)
		{
			if(input[i][j+1]=='#'&&comp[i][j+1]!=c)
			{
				comp[i][j+1] = c;
				spread(c, i, j+1);
			}
		}
	}
	vector<string> originalImage(vector<string> in)
	{
		input = in;
		int index = 0;
		ymax = input.size();
		xmax = input[0].length();
		for(int i=0; i<ymax; i++)
		{
			for(int j=0; j<xmax; j++)
			{
				comp[i][j]=-1;
			}
		}
		for(int i=0; i<ymax; i++)
		{
			for(int j=0; j<xmax; j++)
			{
				if(input[i][j]=='#')
				{
					if(j==0)
					{
						if(i==0)
						{
							comp[i][j] = index;
							index++;
						}
						else
						{
							if(input[i-1][j]=='#')
							{
								comp[i][j] = comp[i-1][j];
							}
							else
							{
								comp[i][j] = index;
								index++;
							}
						}
					}
					else
					{
						if(i==0)
						{
							if(input[i][j-1]=='#')
							{
								comp[i][j] = comp[i][j-1];
							}
							else
							{
								comp[i][j] = index;
								index++;
							}
						}
						else
						{
							if(input[i][j-1]=='#' && input[i-1][j]=='#')
							{
								comp[i][j] = comp[i-1][j];
								for(int itemp = 0; itemp<=i; itemp++)
								{
									for(int jtemp = 0; jtemp<xmax; jtemp++)
									{
										if(comp[itemp][jtemp]==comp[i][j-1])
										{
											comp[itemp][jtemp] = comp[i-1][j];
										}
									}
								}
							}
							else if(input[i][j-1]=='#')
							{
								comp[i][j] = comp[i][j-1];
							}
							else if(input[i-1][j] == '#')
							{
								comp[i][j] = comp[i-1][j];
							}
							else
							{
								comp[i][j] = index;
								index++;
							}
						}
					}
				}				
			}
		}
		//done labeling
		bool changed = true;
		while(changed)
		{
			changed = false;
			for(int j=0; j<xmax; j++)
			{
				for(int i=0; i<ymax; i++)
				{
					for(int i2 = i+1; i2<ymax; i2++)
					{
						if(comp[i][j]==comp[i2][j]&& comp[i][j]!=-1)
						{
							for(int i3 = i+1; i3<i2; i3++)
							{
								if(input[i3][j]=='.')
								{
									input[i3][j] = '#';
									changed = true;
								}
								comp[i3][j] = comp[i][j];
								spread(comp[i3][j], i3, j);
							}
						}
					}
				}
			}
			for(int i=0; i<ymax; i++)
			{
				for(int j=0; j<xmax; j++)
				{
					for(int j2 = j+1; j2<xmax; j2++)
					{
						if(comp[i][j]==comp[i][j2]&& comp[i][j]!=-1)
						{
							for(int j3 = j+1; j3<j2; j3++)
							{
								if(input[i][j3]=='.')
								{
									input[i][j3] = '#';
									changed = true;
								}
								comp[i][j3] = comp[i][j];
								spread(comp[i][j3], i, j3);
							}
						}
					}
				}
			}
		}
		return input;
	}
};
