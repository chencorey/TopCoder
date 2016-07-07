// https://community.topcoder.com/stat?c=problem_statement&pm=8467&rd=12180
// This problem was used for: 
// Single Round Match 408 Round 1 - Division II, Level Two

#include <vector>
#include <algorithm>
using namespace std;
class OlympicCandles
{
	public:
	int numberOfNights(vector<int> candles)
	{
		int night = 1;
		while(true)
		{
			sort(candles.begin(), candles.end());
			if(night>candles.size()) return night-1;
			for(int i = candles.size()-1; i+night>=candles.size(); i--)
			{
				if(candles[i]==0) return night-1;
				candles[i]--;
			}
			night++;
		}
	}
};
