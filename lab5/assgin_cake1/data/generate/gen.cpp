/*
随机数据生成器
./gen 100
*/
#include <iostream>
#include <array>
#include <fstream>
#include <unordered_set>
#include "testlib.h"
using namespace std;




// 每一项分别为 s 长度范围，t 长度范围，字符范围，wnext参数
vector<tuple<int, int, int>> tests {
  {10, 10, 10},
  {10, 10, 10},
  {50, 50, 50},
  {50, 50, 50},
  {100, 100, 100},
  {1000, 1000, 1000},
  {1000, 1000, 1000},
  {5000, 5000, 5000},
  {10000, 10000, 1000000000},
  {100000, 100000, 1000000000}
};

vector<int> gen_unique_rand(int n, int l, int r) {
  unordered_set<int> t;
  while(t.size() < n) {
    t.insert(rnd.next(l, r));
  }
  return vector<int>(t.begin(), t.end());
}

void gen(string path, vector<tuple<int,int,int>>& data_limits) {
  ofstream ifs(path);
  if(!ifs.is_open()) {
    std::cout << "open input_file failed" << std::endl;
    return;
  }

  ifs << data_limits.size() << "\n";

  for(int t = 0; t < data_limits.size(); t++){
    auto &[n, m, k] = data_limits[t];
    n = rnd.next(n / 3 * 2, n);
    m = rnd.next(m / 3 * 2, m);
    ifs << n << ' ' << m << '\n';
    for(int i = 1; i <= n; i++) {
      ifs << rnd.next(1, k) << " ";
    }
    ifs << "\n";
    for(int i = 1; i <= m; i++) {
      ifs << rnd.next(1, k) << " ";
    }
    ifs << "\n";
  }
  ifs.close();
}


int main(int argc, char* argv[]){
  registerGen(argc, argv, 1);
  gen("../test/data.in", tests);

  return 0;
}