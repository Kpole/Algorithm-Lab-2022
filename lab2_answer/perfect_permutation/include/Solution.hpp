#if __has_include("util.hpp")
#include "util.hpp"
#endif

class Solution {
public:
  vector<int> perfect_permutation(int n) {
    if(n == 1) return {1};
    else {
      auto a = perfect_permutation(n / 2);
      auto b = perfect_permutation((n + 1) / 2);
      for(auto &x : a) x *= 2;
      for(auto &y : b) a.push_back(y * 2 - 1);
      return a;
    }
  }
};