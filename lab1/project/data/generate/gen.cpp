/*
随机数据生成器
*/
#include <iostream>
#include <array>
#include <fstream>
#include "testlib.h"
using namespace std;


// 正确性测试数据规模，每一项分别为数组大小，元素下界，元素上界
vector<tuple<int, int, int>> samples {
  {5, 0, 10},
  {10, 0, 10},
  {50, 0, 100},
  {100, 0, 100},
  {500, 0, 500},
  {1000, 0, 1000},
  {1000, -1000, 1000},
  {2000, -2000, 2000},
  {2000, INT_MIN, INT_MAX},
  {10000, INT_MIN, INT_MAX}
};

// 性能测试数据规模，每一项分别为数组大小，元素下界，元素上界
vector<tuple<int, int, int>> tests {
  {10, INT_MIN, INT_MAX},
  {100, INT_MIN, INT_MAX},
  {1000, INT_MIN, INT_MAX},
  {5000, INT_MIN, INT_MAX},
  {10000, INT_MIN, INT_MAX},
  {50000, INT_MIN, INT_MAX},
  {100000, INT_MIN, INT_MAX}
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

  // 分别生成正确性测试数据和性能测试数据
  gen("../samples/data.in", samples);
  gen("../test/data.in", tests);

  return 0;
}