#if __has_include("util.hpp")
#include "util.hpp"
#endif

class Solution {
public:
  long long minimum_spanning_tree(int n, vector<vector<int>>& edges){
    using ll = long long;
    vector<vector<pair<int, int>>> e(n + 1);
    vector<int> d(n + 1, INT_MAX), v(n + 1);
    for(auto &edge : edges) {
      int x = edge[0], y = edge[1], z = edge[2];
      e[x].push_back({y, z});
      e[y].push_back({x, z});
    }
    d[1] = 0;
    for(int i = 1; i <= n; i++) {
      int x = 0;
      for(int j = 1; j <= n; j++) {
        if(v[j] == 0 && (x == 0 || d[x] > d[j])) x = j;
      }
      v[x] = 1;
      for(int j = 0; j < e[x].size(); j++) {
        int y = e[x][j].first, z = e[x][j].second;
        if(v[y] == 0 && d[y] > z) {
          d[y] = z;
        }
      }
    }
    long long res = 0;
    for(int i = 1; i <= n; i++) res += d[i];
    return res;
  }
};