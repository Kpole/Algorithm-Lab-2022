#include "include/Solution.hpp"

string test_input_file = "./data/test/data.in";

int main(){
  ifstream ifs(test_input_file);
  if(ifs.is_open() == false) {
    cerr << "Failed to open file, check file existence!\n";
    return -1;
  }

  auto check = [&](int n, vector<int> & A) {
    if(A.size() != n) return false;
    auto B = A;
    sort(B.begin(), B.end());
    for(int i = 0; i < n; i++) if(B[i] != i + 1) return false;

    vector<int> v(n + 1);
    for(int i = 0; i < n; i++) v[A[i]] = i;
    for(int i = 0; i < n; i++){
      for(int j = i + 1; j < n; j++){
        int sum = A[i] + A[j];
        if(sum % 2 == 0 && sum / 2 <= n) {
          int k = v[sum / 2];
          if(k > i && k < j) return false;
        }
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
    auto my_ans = sol.perfect_permutation(n);
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