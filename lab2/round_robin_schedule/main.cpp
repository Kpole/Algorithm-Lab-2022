#include "include/Solution.hpp"

string test_input_file = "./data/test/data.in";

int main(){
  ifstream ifs(test_input_file);
  if(ifs.is_open() == false) {
    cerr << "Failed to open file, check file existence!\n";
    return -1;
  }

  auto check = [&](int n, vector<vector<int>>& A) {
    assert(__builtin_popcount(n) == 1);
    vector<bool> v(n);
    for(int i = 0; i < n; i++) {
      if(A[i][0] != i + 1) return false;
      fill(v.begin(), v.end(), 0);
      for(int j = 0; j < n; j++){
        if(v[A[i][j] - 1] == 1) return false;
        v[A[i][j] - 1] = 1;
      }
      fill(v.begin(), v.end(), 0);
      for(int j = 0; j < n; j++){
        if(v[A[j][i] - 1] == 1) return false;
        v[A[i][j] - 1] = 1;
      }
    }
    return true;
  };

  int T = 0, succ_cnt = 0;
  ifs >> T;
  cout << "Total number of sample tests: "<< T << endl;

  for(int t = 1; t <= T; t ++){
    int n;
    ifs >> n;
    Solution sol;
    auto my_ans = sol.round_robin_schedule(n);
    if (!check(n, my_ans)) {
        cerr << "Sample Test Round " << t << ": \t" << RED << " Wrong Answer" << END << endl;
        debug(my_ans);
    } else {
        cerr << "Sample Test Round " << t << ": \t" << GREEN << " Accepted" << END << endl;
        succ_cnt ++;
    }
  }
  if(succ_cnt != T) {
    cout << "The percentage of successful samples: " << succ_cnt << "/" << T << endl;
  } else {
    cout << GREEN << "Congratulation, you have passed all test cases!" << END << endl;
  }
}