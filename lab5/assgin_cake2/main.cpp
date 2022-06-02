#include "include/Solution.hpp"

string test_input_file = "./data/test/data.in";
string test_output_file = "./data/test/data.out";

void test() {
  ifstream ifs(test_input_file);
  ifstream ofs(test_output_file);

  if(ifs.is_open() == false || ofs.is_open() == false) {
    cerr << "Failed to open file, check file existence!\n";
    return;
  }

  int T = 0, succ_cnt = 0;
  ifs >> T;
  cout << "Total number of sample tests: "<< T << endl;
  for(int t = 1; t <= T; t ++){
    int n, m;
    ifs >> n >> m;
    vector<vector<int>> g(n, vector<int>(2, 0)), s(m, vector<int>(2, 0));
    for(int i = 0; i < n; i++) ifs >> g[i][0] >> g[i][1];
    for(int i = 0; i < m; i++) ifs >> s[i][0] >> s[i][1];

    Solution sol;
    int res = sol.assign_cake(g, s);
    int ans;
    ofs >> ans;
    
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

int main(){

  test();

  return 0;
}