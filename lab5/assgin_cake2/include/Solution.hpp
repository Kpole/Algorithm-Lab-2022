#if __has_include("util.hpp")
#include "util.hpp"
#endif

class Solution {
public:
  int assign_cake(vector<vector<int>>& g, vector<vector<int>>& s) {
    int n = g.size(), m = s.size();

    sort(g.begin(), g.end(), [](const vector<int> &lth, const vector<int> &rth) {
      return lth[1] < rth[1];
    });

    sort(s.begin(), s.end(), [](const vector<int> &lth, const vector<int> &rth) {
      return lth[0] < rth[0];
    });

    int res = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(s[j][1] > 0 && s[j][0] >= g[i][0] && s[j][0] <= g[i][1]) {
          res ++;
          s[j][1] --;
          break;
        }
      }
    }
    return res;
  }
};