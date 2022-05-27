#include "include/Solution.hpp"

string test_input_file = "./data/test/data.in";
string test_output_file = "./data/test/data.out";

int main(){
  ifstream ifs(test_input_file);
  ifstream ofs(test_output_file);

  if(ifs.is_open() == false || ofs.is_open() == false) {
    cerr << "Failed to open file, check file existence!\n";
    return -1;
  }

  int T = 0, succ_cnt = 0;
  ifs >> T;
  cout << "Total number of sample tests: "<< T << endl;
  for(int t = 1; t <= T; t ++){
    int n;
    ifs >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
      ifs >> nums[i];
    }
    Solution sol;
    long long res = sol.find_maximum_subarray(nums);
    long long ans; ofs >> ans;
    if(compare_result("Sample Test Round " + to_string(t), res, ans)) {
      succ_cnt ++;
    }
  }
  if(succ_cnt != T) {
    cout << "The percentage of successful samples: " << succ_cnt << "/" << T << endl;
  } else {
    cout << GREEN << "Congratulation, you have passed all test cases!" << END << endl;
  }
}