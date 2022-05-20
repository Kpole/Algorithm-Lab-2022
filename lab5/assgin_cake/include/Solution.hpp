#if __has_include("util.hpp")
#include "util.hpp"
#endif

class Solution {
public:
  int assign_cake(vector<int> g, vector<int> s) {
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int i = 0, j = 0, n = g.size(), m = s.size();
    int res = 0;
    for(;i<n;i++){
        while(j < m && s[j] < g[i]) j++;
        if(j < m) {
            res ++;
            j ++;
        } else break;
    }
    return res;
  }
};