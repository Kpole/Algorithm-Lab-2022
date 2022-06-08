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

  vector<vector<int>> three_sum(vector<int> &A, vector<int> &B, vector<int> &C)
  {
    // 使A，B成为递增序列
    vector<vector<int>> res;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (int k = 0; k < C.size(); k++)
    {
      int i = 0, j = B.size() - 1;
      while (i < A.size())
      {
        if (j >= 0)
        {
          if (A[i] + B[j] == C[k])
          {
            vector<int> temp = {A[i], B[j], C[k]};
            res.push_back(temp);
            i++;
            j--;
          }
          else if (A[i] + B[j] < C[k])
          {
            i++;
          }
          else
          {
            j--;
          }
        }
        else
        {
          break;
        }
      }
    }
    return res;
  }
};