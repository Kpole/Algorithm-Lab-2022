#if __has_include("util.hpp")
#include "util.hpp"
#endif

class Solution {
public:
  long long build_roads(int n, vector<int>& w, vector<vector<int>>& edges){
    using ll = long long;
    vector<int> f(n + 1);
    for(int i = 1; i <= n; i++) f[i] = i;
    function<int(int)> get = [&](int x) {
      return x == f[x] ? x : f[x] = get(f[x]);
    };
    for(int i = 0; i < n; i++) {
      edges.push_back({i, n, w[i]});
    }
    ll res = 0;
    sort(edges.begin(), edges.end(), [&](vector<int>& lth, vector<int>& rth) {
      return lth[2] < rth[2];
    });
    for(auto &e : edges) {
      int x = e[0], y = e[1], z = e[2];
      x = get(x), y = get(y);
      if(x == y) continue;
      res += z;
      f[x] = y;
    }
    return res;
  }
};