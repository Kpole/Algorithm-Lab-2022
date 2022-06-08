#if __has_include("util.hpp")
#include "util.hpp"
#endif

class Solution
{
public:
  vector<vector<int>> three_sum_brute_force(vector<int> A, vector<int> B, vector<int> C)
  {
    vector<vector<int>> res;
    for (int i = 0; i < A.size(); i++)
    {
      for (int j = 0; j < B.size(); j++)
      {
        for (int k = 0; k < C.size(); k++)
        {
          if (C[k] == A[i] + B[j])
          {
            vector<int> temp = {A[i], B[j], C[k]};
            res.push_back(temp);
          }
        }
      }
    }
    return res;
  }
  
  vector<vector<int>> three_sum(vector<int>& A, vector<int>& B, vector<int> &C) {
    // 请在这里完成你的代码
  }
};