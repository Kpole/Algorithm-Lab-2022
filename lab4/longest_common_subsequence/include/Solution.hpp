#if __has_include("util.hpp")
#include "util.hpp"
#endif

class Solution {
  void print_table(vector<vector<int>> &table) {
    debug(table);
  }
public:
  int lcs(string s, string t, vector<vector<int>> &c, vector<vector<int>> &b) {
    // 注意，string 类型是 C++ 的字符串类型，可以通过 s[0] 来访问 s 的第一个字符
    int n = s.size(), m = t.size();
    c.resize(n + 1);
    b.resize(n + 1);
    for(int i = 0; i <= n; i++) {
      c[i].resize(m + 1, 0);
      b[i].resize(m + 1, 0);
    }
  }

  // print_lcs 只用于调试，不做正确性检测
  void print_lcs(vector<vector<int>> &b, string &s, int i, int j) {
    
  }
};