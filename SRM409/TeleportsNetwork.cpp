// https://community.topcoder.com/stat?c=problem_statement&pm=9830&rd=12181
// This problem was used for: 
// Single Round Match 409 Round 1 - Division II, Level Three

#include <vector>
#include <algorithm>
using namespace std;
class TeleportsNetwork
{
	public:
	int pathLengths[50][50];
	int tpCount;
	int N;
	int result;
	void minInconvenience(vector<int> tps)
	{
		if(tps.size()==tpCount)
		{
			int mostInconvenience = 0;
			tps.push_back(0);
			for(int i = 0; i<N; i++)
			{
				int best = 100;
				for(int j = 0; j<tps.size(); j++)
				{
					best = min(best, pathLengths[i][tps[j]]);
				}
				mostInconvenience = max(mostInconvenience, best);
			}
			result = min(result, mostInconvenience);
		}
		else
		{
			int start = 1;
			if(tps.size()>0) start = tps[tps.size()-1]+1;
			for(int i = start; i<N; i++)
			{
				vector<int> temp = tps;
				temp.push_back(i);
				minInconvenience(temp);
			}
		}
	}
	int distribute(int teleportCount, vector<int> citiesX, vector<int> citiesY)
	{
		result = 50;
		tpCount = teleportCount;
		N = citiesX.size();
		bool edges[50][50];
		for(int i = 0; i<50; i++)
		{
			for(int j = 0; j<50; j++)
			{
				edges[i][j] = false;
			}
		}
		long long distances[50][50];
		for(int i = 0; i<citiesX.size(); i++)
		{
			for(int j = 0; j<citiesX.size(); j++)
			{
				distances[i][j] = ((long long)citiesX[i]-(long long)citiesX[j])*((long long)citiesX[i]-(long long)citiesX[j])+((long long)citiesY[i]-(long long)citiesY[j])*((long long)citiesY[i]-(long long)citiesY[j]);
			}
		}
		for(int i = 1; i<citiesX.size(); i++)
		{
			long long closest = 10000000000000;
			int closestIndex = -1;
			int closestX = -1;
			int closestY = -1;
			for(int j = 0; j<citiesX.size(); j++)
			{
				if(distances[0][j]<distances[0][i])
				{
					if(distances[i][j]<closest)
					{
						closest = distances[i][j];
						closestIndex = j;
						closestX = citiesX[j];
						closestY = citiesY[j];
					}
					else if(distances[i][j]==closest)
					{
						if(citiesX[j]<closestX||(citiesX[j]==closestX&&citiesY[j]<closestY))
						{
							closest = distances[i][j];
							closestIndex = j;
							closestX = citiesX[j];
							closestY = citiesY[j];
						}
					}
				}
			}
			edges[i][closestIndex] = true;
			edges[closestIndex][i] = true;
		}
		for(int i = 0; i<citiesX.size(); i++)
		{
			for(int j = 0; j<citiesX.size(); j++)
			{
				if(i==j)pathLengths[i][j] = 0;
				else if(edges[i][j])pathLengths[i][j] = 1;
				else pathLengths[i][j] = 100;
			}
		}
		for(int i = 0; i<citiesX.size(); i++)
		{
			for(int j = 0; j<citiesX.size(); j++)
			{
				for(int k = 0; k<citiesX.size(); k++)
				{
					pathLengths[j][k] = min(pathLengths[j][k], pathLengths[j][i]+pathLengths[i][k]);
				}
			}
		}
		vector<int> temp;
		minInconvenience(temp);
		return result;
	}
};
