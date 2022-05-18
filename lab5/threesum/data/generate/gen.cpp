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
vector<tuple<int, int, int, int, int>> tests {
  {5, 6, 7, -10, 10},
  {10, 10, 15, -10, 10},
  {100, 100, 150, -150, 150},
  {100, 100, 200, -1000, 1000},
  {100, 100, 200, -1000, 1000},
  {200, 200, 300, -10000, 10000},
  {200, 200, 300, -10000, 10000},
  {300, 300, 300, -10000, 10000},
  {300, 300, 300, -10000, 10000},
  {300, 300, 300, -10000, 10000},
};

vector<int> gen_unique_rand(int n, int l, int r) {
  unordered_set<int> t;
  while(t.size() < n) {
    t.insert(rnd.next(l, r));
  }
  return vector<int>(t.begin(), t.end());
}

void gen(string path, vector<tuple<int,int,int,int,int>>& data_limits) {
  ofstream ifs(path);
  if(!ifs.is_open()) {
    std::cout << "open input_file failed" << std::endl;
    return;
  }

  ifs << data_limits.size() << "\n";

  for(int t = 0; t < data_limits.size(); t++){
    auto &[n, m, p, l, r] = data_limits[t];
    n = rnd.next(n / 2, n);
    m = rnd.next(m / 2, m);
    p = rnd.next(p / 2, p);
    ifs << n << ' ' << m  << ' ' << p << "\n";
    auto a = gen_unique_rand(n, l, r);
    auto b = gen_unique_rand(m, l, r);
    vector<int> c(p);
    for(int i = 0; i < n; i++){
      ifs << a[i] << ' ';
    }
    ifs << "\n";
    
    for(int j = 0; j < m; j++){
      ifs << b[j] << ' ';
    }
    ifs << "\n";
    int cnt = 0;
    for(int i = 0; i < p; i++){
      int type = rnd.next(1, 2);
      if(type == 1) {
        cnt ++;
        int x = rnd.next(n);
        int y = rnd.next(m);
        c[i] = a[x] + b[y];
      } else {
        c[i] = rnd.next(l + l, r + r);
      }
      ifs << c[i] << ' ';
    }
    cout << cnt << endl;
    ifs << "\n";
  }
  ifs.close();
}


int main(int argc, char* argv[]){
  registerGen(argc, argv, 1);
  gen("../test/data.in", tests);

  return 0;
}