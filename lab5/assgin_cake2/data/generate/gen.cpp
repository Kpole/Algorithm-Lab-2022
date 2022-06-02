/*
随机数据生成器
*/
#include <iostream>
#include <array>
#include <fstream>
#include <unordered_set>
#include "testlib.h"
using namespace std;




// 每一项分别为 s 长度范围，t 长度范围，字符范围，wnext参数
vector<tuple<int, int, int, int, int>> tests {
  {5, 2, 20, 20, 5},
  {10, 3, 20, 20, 5},
  {100, 20, 100, 100, 5},
  {100, 20, 100, 100, 5},
  {500, 50, 500, 500, 5},
  {500, 100, 500, 500, 5},
  {1000, 50, 1000, 1000, 5},
  {1000, 200, 1000, 1000, 5},
  {2500, 2500, 300, 1000, 1},
  {2500, 50, 1000, 100, 1000},
};


void gen(string path, vector<tuple<int, int, int, int, int>>& data_limits) {
  ofstream ifs(path);
  if(!ifs.is_open()) {
    std::cout << "open input_file failed" << std::endl;
    return;
  }

  ifs << data_limits.size() << "\n";

  for(int t = 0; t < data_limits.size(); t++){
    auto [n, m, L1, L2, L3] = data_limits[t];
    ifs << n << ' ' << m << '\n';
    for(int i = 1; i <= n; i++) {
      int l = rnd.next(1, L1);
      int r = rnd.next(1, L1);
      if(l > r) swap(l, r);
      ifs << l << ' ' << r << "\n";
    }
    for(int i = 1; i <= m; i++) {
      int x = rnd.next(1, L2);
      int y = rnd.next(1, L3);
      ifs << x << ' ' << y << "\n";
    }
  }
  ifs.close();
}


int main(int argc, char* argv[]){
  registerGen(argc, argv, 1);
  gen("../test/data.in", tests);

  return 0;
}