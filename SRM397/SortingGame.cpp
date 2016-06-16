// https://community.topcoder.com/stat?c=problem_statement&pm=8745&rd=12169
// This problem was used for: 
// Single Round Match 397 Round 1 - Division I, Level One 
// Single Round Match 397 Round 1 - Division II, Level Two

#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <queue>
#include <iterator>
#include <map>
using namespace std;
class SortingGame
{
	public:
	int fewestMoves(vector<int> input, int k)
	{
		map<vector<int>, int> dist;
    dist[input] = 0;
 
    queue<vector<int> > Q;
    Q.push(input);
 
    int i, N = input.size();
 
    while (!Q.empty()) {
      vector<int> u = Q.front(); Q.pop();
      int d = dist[u];
 
      for (i = 1; i < N; i++)
        if (u[i-1] > u[i]) break;
      if (i == N) return d;
 
      for (i = 0; i + k <= N; i++) {
        vector<int> w = u;
        reverse(w.begin() + i, w.begin() + i + k);
        if (dist.count(w) == 0) {
          dist[w] = d + 1;
          Q.push(w);
        }
      }
    }
 
    return -1;    
  }
};
