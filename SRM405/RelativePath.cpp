// https://community.topcoder.com/stat?c=problem_statement&pm=9760&rd=12177
// This problem was used for: 
// Single Round Match 405 Round 1 - Division I, Level One 
// Single Round Match 405 Round 1 - Division II, Level Two

#include <string>
using namespace std;
class RelativePath
{
	public:
	string makeRelative(string path, string currentDir)
	{
		if(currentDir=="/")
		{
			return path.substr(1);
		}
		int lastSlash = -1;
		for(int i = 0; i<path.length()&&i<currentDir.length(); i++)
		{
			if(path[i]!=currentDir[i])
			{
				break;
			}
			else if(path[i]=='/')
			{
				lastSlash = i;
			}
			else if(i==currentDir.length()-1&&path.length()>currentDir.length()&&path[i+1]=='/')
			{
				return path.substr(i+2);
			}
		}
		int remainingSlashes = 0;
		for(int i = lastSlash+1; i<currentDir.length(); i++)
		{
			if(currentDir[i]=='/') remainingSlashes++;
		}
		string relpath;
		for(int i = 0; i<=remainingSlashes; i++)
		{
			relpath +="../";
		}
		relpath+=path.substr(lastSlash+1);
		return relpath;
	}
};
