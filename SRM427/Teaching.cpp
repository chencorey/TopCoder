// https://www.topcoder.com/stat?c=problem_statement&pm=10044&rd=13518
// This problem was used for: 
// Single Round Match 427 Round 1 - Division II, Level Three

#include <vector>
#include <string>
using namespace std;
class Teaching
{
	public:
	int K;
	vector<string> w;
	int result;
	void process(int letters, int count, char last)
	{
		if(count<K)
		{
			char curr;
			if(count==0) curr = 'a';
			else curr = last+1;
			while(curr<='z')
			{
				if(curr!='a'&&curr!='c'&&curr!='i'&&curr!='n'&&curr!='t')
				{
					letters+=(1<<(curr-'a'));
					process(letters, count+1, curr);
					letters-=(1<<(curr-'a'));
				}
				curr++;
			}
			return;
		}
		else
		{
			letters+=(1<<('a'-'a'));
			letters+=(1<<('c'-'a'));
			letters+=(1<<('i'-'a'));
			letters+=(1<<('n'-'a'));
			letters+=(1<<('t'-'a'));
			int count = 0;
			for(int i =0; i<w.size(); i++)
			{
				count++;
				for(int j = 4; j<w[i].length()-4; j++)
				{
					if((letters&(1<<(w[i][j]-'a')))==0)
					{
						count--;
						break;
					}
				}
			}
			result = max(result, count);
		}
	}
	int count(vector<string> words, int knum)
	{
		K=knum-5;
		w = words;
		result = 0;
		if(K<0) return 0;
		process(0, 0, 'a');
		return result;
	}
};
