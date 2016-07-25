// https://community.topcoder.com/stat?c=problem_statement&pm=9954&rd=13506
// This problem was used for: 
// Single Round Match 415 Round 1 - Division II, Level Two

#include <string>
#include <vector>
using namespace std;
class ThreePhotos
{
	public:
	int removeCubes(vector<string> A, vector<string> B, vector<string> C)
	{
		bool c[50][50][50];
		for(int i = 0; i<A.size(); i++)
		{
			for(int j = 0; j<A.size(); j++)
			{
				for(int k = 0; k<A.size(); k++)
				{
					c[i][j][k] = true;
				}
			}
		}
		for(int i = 0; i<A.size(); i++)
		{
			for(int j = 0; j<A.size(); j++)
			{
				if(A[i][j]=='N')
				{
					for(int k = 0; k<A.size(); k++)
					{
						c[i][j][k] = false;
					}
				}
			}
		}
		for(int i = 0; i<A.size(); i++)
		{
			for(int j = 0; j<A.size(); j++)
			{
				if(B[i][j]=='N')
				{
					for(int k = 0; k<A.size(); k++)
					{
						c[i][k][j] = false;
					}
				}
			}
		}
		for(int i = 0; i<A.size(); i++)
		{
			for(int j = 0; j<A.size(); j++)
			{
				if(C[i][j]=='N')
				{
					for(int k = 0; k<A.size(); k++)
					{
						c[k][i][j] = false;
					}
				}
			}
		}
		//valid A
		for(int i = 0; i<A.size(); i++)
		{
			for(int j = 0; j<A.size(); j++)
			{
				bool check = true;
				for(int k = 0; k<A.size(); k++)
				{
					check = check && !c[i][j][k];
				}
				if((A[i][j]=='N'&&!check)||(A[i][j]=='Y'&&check))
				{
					return -1;
				}
			}
		}
		//valid B
		for(int i = 0; i<A.size(); i++)
		{
			for(int j = 0; j<A.size(); j++)
			{
				bool check = true;
				for(int k = 0; k<A.size(); k++)
				{
					check = check && !c[i][k][j];
				}
				if((B[i][j]=='N'&&!check)||(B[i][j]=='Y'&&check))
				{
					return -1;
				}
			}
		}
		//valid C
		for(int i = 0; i<A.size(); i++)
		{
			for(int j = 0; j<A.size(); j++)
			{
				bool check = true;
				for(int k = 0; k<A.size(); k++)
				{
					check = check && !c[k][i][j];
				}
				if((C[i][j]=='N'&&!check)||(C[i][j]=='Y'&&check))
				{
					return -1;
				}
			}
		}
		int result = 0;
		for(int i = 0; i<A.size(); i++)
		{
			for(int j = 0; j<A.size(); j++)
			{
				for(int k = 0; k<A.size(); k++)
				{
					if(!c[i][j][k])result++;
				}
			}
		}
		return result;
	}
};
