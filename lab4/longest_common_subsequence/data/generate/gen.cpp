/*
随机数据生成器
./gen 100
*/
#include <iostream>
#include <array>
#include <fstream>
#include "testlib.h"
using namespace std;




// 每一项分别为 s 长度范围，t 长度范围，字符范围，wnext参数
vector<tuple<int, int, int, int, int>> tests {
  {20, 20, 10, 0, 0},
  {20, 20, 10, 0, 0},
  {50, 50, 20, 0, 0},
  {50, 50, 20, 0, 0},
  {50, 50, 20, -1, 1},
  {50, 50, 20, -1, 1},
  {100, 100, 20, 0, 0},
  {100, 100, 20, -1, 1},
  {500, 500, 20, 0, 0},
  {1000, 1000, 25, 0, 0},
};

void gen(string path, vector<tuple<int,int,int,int,int>>& data_limits) {
  ofstream ifs(path);
  if(!ifs.is_open()) {
    std::cout << "open input_file failed" << std::endl;
    return;
  }

  ifs << data_limits.size() << "\n";

  for(int t = 0; t < data_limits.size(); t++){
    auto &[n, m, up, P1, P2] = data_limits[t];
    n = rnd.next(n / 2, n);
    m = rnd.next(m / 2, m);
    for(int i = 0; i < n; i++) {
      int c = rnd.wnext(0, up, P1);
      ifs << char('A' + c);
    }
    ifs << "\n";
    for(int i = 0; i < m; i++) {
      int c = rnd.wnext(0, up, P2);
      ifs << char('A' + c);
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