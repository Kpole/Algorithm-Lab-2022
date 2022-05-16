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
    string s, p;
    ifs >> s >> p;
    vector<vector<int>> b, c;
    Solution sol;
    int res = sol.lcs(s, p, c, b);
    int ans; ofs >> ans;
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
  string s = "AGCTAG";
  string t = "ACTCC";
  int n = s.size(), m = t.size();
  vector<vector<int>> b, c;

  Solution sol;
  // 求解 LCS 长度
  int res = sol.lcs(s, t, c, b);

  cout << BLUE << "[test case]" << END << endl;
  cout << "s: " << s << endl;
  cout << "t: " << t << endl;
  cout << "Length of LCS: " <<  res << endl;
  cout << "LCS is: ";
  sol.print_lcs(b, s, n, m);
  cout << endl;

  // test();

  return 0;
}