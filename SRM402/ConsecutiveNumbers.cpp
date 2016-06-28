// https://community.topcoder.com/stat?c=problem_statement&pm=8302&rd=12174
// This problem was used for: 
// Single Round Match 402 Round 1 - Division II, Level Two

#include <vector>
using namespace std;
class ConsecutiveNumbers
{
	public:
	vector<int> missingNumber(vector<int> numbers)
	{
		vector<int> output;
		int mink = 1000000001;
		int maxk = 0;
		for(int i =0; i<numbers.size(); i++)
		{
			mink = min(mink, numbers[i]);
			maxk = max(maxk, numbers[i]);
			for(int j = i+1; j<numbers.size(); j++)
			{
				if(numbers[i]==numbers[j]) return output;
			}
		}
		if(maxk-mink>numbers.size())
		{
			return output;
		}
		if(maxk-mink==numbers.size())
		{
			for(int i =mink; i<=maxk; i++)
			{
				bool found = false;
				for(int j =0; j<numbers.size(); j++)
				{
					if(i==numbers[j])found = true;
				}
				if(!found)
				{
					output.push_back(i);
					return output;
				}
			}
		}
		else
		{			
			if(mink!=1)output.push_back( mink-1);
			output.push_back(maxk+1);
			return output;
		}
	}
};
