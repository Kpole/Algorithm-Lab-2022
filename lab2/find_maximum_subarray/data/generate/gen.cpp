/*
随机数据生成器
*/
#include <iostream>
#include <array>
#include <fstream>
#include "testlib.h"
using namespace std;




// 每一项分别为数组大小，元素下界，元素上界
vector<tuple<int, int, int>> tests {
  {10, -10, 10},
  {10, -10, 10},
  {20, -10, 10},
  {20, -100, 100},
  {20, -100, 100},
  {100, -1000, 1000},
  {1000, -1000, 1000},
  {5000, -1000, 1000},
  {10000, -1000, 1000},
  {50000, -1000, 1000},
  {100000, -10000, 10000}
};

void gen(string path, vector<tuple<int,int,int>>& data_limits) {
  ofstream ifs(path);
  if(!ifs.is_open()) {
    std::cout << "open input_file failed" << std::endl;
    return;
  }

  ifs << data_limits.size() << "\n";

  for(int t = 0; t < data_limits.size(); t++){
    auto &[n, l, r] = data_limits[t];
    ifs << n << "\n";
    for(int i = 0; i < n; i++){
      ifs << rnd.next(l, r) << " \n"[i == n - 1];
    }
  }
  ifs.close();
}


int main(int argc, char* argv[]){
  registerGen(argc, argv, 1);
  gen("../test/data.in", tests);

  return 0;
}