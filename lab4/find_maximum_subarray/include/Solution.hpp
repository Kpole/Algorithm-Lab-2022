#if __has_include("util.hpp")
#include "util.hpp"
#endif

class Solution {
public:
  using ll = long long;
  long long find_maximum_subarray(vector<int> &A) {
    int n = A.size();
    ll sum = 0, rs = LLONG_MIN;
    for(int i = 0; i < n; i++){
      sum = max(sum + A[i], 1ll * A[i]);
      rs = max(rs, sum);
    }
    return rs;
  }
};