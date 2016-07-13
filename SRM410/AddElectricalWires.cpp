// https://community.topcoder.com/stat?c=problem_statement&pm=8817&rd=12182
// This problem was used for: 
// Single Round Match 410 Round 1 - Division I, Level One 
// Single Round Match 410 Round 1 - Division II, Level Two

#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class AddElectricalWires
{
	public:
	int maxNewWires(vector<string> wires, vector<int> gridConnections)
	{
		vector<vector<int> > gridPieces;
		int mostWires = 0;
		bool wireUsed[50];
		int result = 0;
		for(int i = 0; i<wires.size(); i++)
		{
			wireUsed[i] = false;
		}
		for(int i = 0; i<gridConnections.size(); i++)
		{
			vector<int> piece;
			vector<int> temp;
			temp.push_back(gridConnections[i]);
			while(temp.size()>0)
			{
				vector<int> targets;
				for(int j = 0; j<temp.size(); j++)
				{					
					for(int k = 0; k<wires[temp[j]].length(); k++)
					{
						if(wires[temp[j]][k]=='1'&&find(piece.begin(), piece.end(), k)==piece.end()&&find(targets.begin(), targets.end(), k)==targets.end()&&find(temp.begin(), temp.end(), k)==temp.end())
						{
							targets.push_back(k);
						}
					}
					piece.push_back(temp[j]);
					wireUsed[temp[j]] = true;
				}
				temp = targets;
			}
			mostWires = max(mostWires, (int)piece.size());
			gridPieces.push_back(piece);
		}
		vector<int> unusedWires;
		for(int i = 0; i<wires.size(); i++)
		{
			if(!wireUsed[i])
			{
				unusedWires.push_back(i);
			}
		}
		for(int i = 0; i<unusedWires.size(); i++)
		{
			for(int j = i+1; j<unusedWires.size(); j++)
			{
				if(wires[unusedWires[i]][unusedWires[j]]=='0') result++;
			}
		}
		for(int i = 0; i<gridPieces.size(); i++)
		{
			for(int j = 0; j<gridPieces[i].size(); j++)
			{
				for(int k = j+1; k<gridPieces[i].size(); k++)
				{
					if(wires[gridPieces[i][j]][gridPieces[i][k]]=='0') result++;
				}
			}
		}
		result+=mostWires*unusedWires.size();
		return result;
	}
};
