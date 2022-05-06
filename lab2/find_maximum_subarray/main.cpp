#include <iostream>
#include <vector>
#include "include/util.hpp"
using namespace std;

/*
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

void test(Solution sol) {
  std::ifstream ifs(test_input_file);
  std::ifstream ofs(test_output_file);
  if(ifs.is_open() == false || ofs.is_open() == false) {
    std::cerr << "Failed to open file, check file existence!\n";
    return;
  }
  int T = 0, succ_cnt = 0;
  ifs >> T;
  std::cout << "Total number of sample tests: "<< T << std::endl;
  for(int t = 1; t <= T; t ++){
    int n;
    ifs >> n;
    std::vector<int> nums(n);
    for(int i = 0; i < n; i++){
      ifs >> nums[i];
    }
    int res = sol.find_maximum_subarray(nums);
    int ans; ofs >> ans;

    if (ans != res) {
				std::cout << "Sample Test Round " << t << ": \t" << RED << " Wrong Answer" << END << std::endl;
        std::cout << "Correct Answer: " << ans << ", Your Answer: " << res << std::endl;
    } else {
      std::cout << "Sample Test Round " << t << ": \t" << GREEN << " Accepted" << END << std::endl;
      succ_cnt ++;
    }
  }
  if(succ_cnt != T) {
    std::cout << "The percentage of successful samples: " << succ_cnt << "/" << T << std::endl;
  } else {
    std::cout << GREEN << "Congratulation, you have passed all test cases!" << END << std::endl;
  }
}

int main(){
  test(Solution());
}