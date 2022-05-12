#if __has_include("util.hpp")
#include "util.hpp"
#endif

/*
提示：
int范围：
  无穷小可以用 INT_MIN 表示
  无穷大可以用 INT_MAX 表示
long long 范围：
  无穷小可以用 LLONG_MIN 表示
  无穷大可以用 LLONG_MAX 表示
*/

class Solution {
public:
  int find_maximum_crossing_subarray(vector<int> &A, int low, int mid, int high) {
    int left_sum = INT_MIN / 2;
    int sum = 0;
    for(int i = mid; i >= low; i--) {
      sum += A[i];
      left_sum = max(left_sum, sum);
    }
    
    int right_sum = INT_MIN / 2;
    sum = 0;
    for(int i = mid + 1; i <= high; i++){
      sum += A[i];
      right_sum = max(right_sum, sum);
    }
    return max(left_sum, max(right_sum, left_sum + right_sum));
  }
  int find_maximum_subarray(vector<int> &A, int low, int high) {
    if(low == high) return A[low];
    else {
      int mid = (low + high) / 2;
      int lsum = find_maximum_subarray(A, low, mid);
      int rsum = find_maximum_subarray(A, mid + 1, high);
      int msum = find_maximum_crossing_subarray(A, low, mid, high);
      return max(lsum, max(rsum, msum));
    }
  }
  int find_maximum_subarray(vector<int> &A) {
    return find_maximum_subarray(A, 0, A.size() - 1);
  }
};