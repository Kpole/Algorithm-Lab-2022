#if __has_include("util.hpp")
#include "util.hpp"
#endif

class Solution {
public:

  vector<vector<int>> round_robin_schedule(int n) {
    if(n == 1) {
      return {{1}};
    }
    auto rs = round_robin_schedule(n / 2);
    rs.resize(n);
    int m = n / 2;
    for(int i = 0; i < m; i++){
      rs[i].resize(n);
      for(int j = m; j < n; j++){
        rs[i][j] = rs[i][j - m] + m;
      }
    }
    for(int i = m; i < n; i++){
      rs[i].resize(n);
      for(int j = 0; j < m; j++){
        rs[i][j] = rs[i - m][j + m];
      }
      for(int j = m; j < n; j++){
        rs[i][j] = rs[i - m][j - m];
      }
    }
    return rs;
  }
};