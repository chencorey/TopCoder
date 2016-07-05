// https://community.topcoder.com/stat?c=problem_statement&pm=9770&rd=12178
// This problem was used for: 
// Single Round Match 406 Round 1 - Division II, Level One

#include <vector>
#include <string>
using namespace std;
class HappyCells
{
	public:
	vector<int> getHappy(vector<string> grid)
	{
		int oneH = 0, twoH = 0, threeH = 0;
		for(int i = 0; i<grid.size(); i++)
		{
			for(int j = 0; j<grid[i].length(); j++)
			{
				if(grid[i][j]=='X') continue;
				bool isOrthogonal = true;
				bool isDiagonal = true;
				if(i>0&&grid[i-1][j]=='.') isOrthogonal = false;
				if(j>0&&grid[i][j-1]=='.') isOrthogonal = false;
				if(i+1<grid.size()&&grid[i+1][j]=='.') isOrthogonal = false;
				if(j+1<grid[i].length()&&grid[i][j+1]=='.') isOrthogonal = false;
				if(i>0&&j>0&&grid[i-1][j-1]=='.') isDiagonal = false;
				if(i>0&&j+1<grid[i].length()&&grid[i-1][j+1]=='.') isDiagonal = false;
				if(i+1<grid.size()&&j>0&&grid[i+1][j-1]=='.') isDiagonal = false;
				if(i+1<grid.size()&&j+1<grid[i].length()&&grid[i+1][j+1]=='.') isDiagonal = false;
				if(isDiagonal&&isOrthogonal) oneH++;
				if(!isDiagonal&&isOrthogonal) twoH++;
				if(isDiagonal&&!isOrthogonal) threeH++;
			}
		}
		vector<int> result;
		result.push_back(oneH);
		result.push_back(twoH);
		result.push_back(threeH);
		return result;
	}
};
