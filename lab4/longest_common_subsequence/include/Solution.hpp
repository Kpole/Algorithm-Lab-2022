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
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++){
        if(s[i - 1] == t[j - 1]) {
          c[i][j] = c[i - 1][j - 1] + 1;
          b[i][j] = 1;
        } else if (c[i - 1][j] >= c[i][j - 1]) {
          c[i][j] = c[i - 1][j];
          b[i][j] = 0;
        } else {
          c[i][j] = c[i][j - 1];
          b[i][j] = -1;
        }
      }
    }
    return c[n][m];
  }

  // print_lcs 只用于调试，不做正确性检测
  void print_lcs(vector<vector<int>> &b, string &s, int i, int j) {
    if(i == 0 || j == 0) return;
    if(b[i][j] == 1) {
      print_lcs(b, s, i - 1, j - 1);
      cout << s[i - 1];
    } else if (b[i][j] == 0) {
      print_lcs(b, s, i - 1, j);
    } else {
      print_lcs(b, s, i, j - 1);
    }
  }
};