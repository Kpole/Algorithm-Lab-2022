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
    vector<int> w(n);
    for(int i = 0; i < n; i++) ifs >> w[i];
    vector<vector<int>> e;
    e.reserve(m);
    for(int i = 0; i < m; i++) {
      int u, v, w;
      ifs >> u >> v >> w;
      e.push_back({u, v, w});
    }

    Solution sol;
    auto res = sol.build_roads(n, w, e);
    long long ans = 0;
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