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
    int n, m, p;
    ifs >> n >> m >> p;
    vector<int> a(n), b(m), c(p);
    for(int i = 0; i < n; i++) ifs >> a[i];
    for(int i = 0; i < m; i++) ifs >> b[i];
    for(int i = 0; i < p; i++) ifs >> c[i];

    Solution sol;
    auto ans = sol.three_sum(a, b, c);

    vector<vector<int>> res;
    int sz = 0; 
    ofs >> sz;

    for(int i = 0; i < sz; i++){
      int x, y, z; ofs >> x >> y >> z;
      res.push_back({x, y, z});
    }

    sort(ans.begin(), ans.end());
    sort(res.begin(), res.end());
    
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