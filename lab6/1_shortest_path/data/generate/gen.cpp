/*
随机数据生成器
*/
#include <iostream>
#include <array>
#include <fstream>
#include <unordered_set>
#include <assert.h>
#include "testlib.h"
using namespace std;




// n, m, limit, 伸展度
vector<tuple<int, int, int, int>> tests {
  {5, 7, 20, 5},
  {15, 25, 50, 3},
  {30, 100, 50, 3},
  {50, 100, 100, 5},
  {100, 300, 1000, 5},
  {200, 500, 1000, 5},
  {300, 600, 1000, 5},
  {500, 499, 1000, 5},
  {500, 550, 1000, 5},
  {1000, 1500, 1000, 5},
  {1000, 999, 1000, 10},
  {1000, 2000, 1E9, 10},
  {1000, 2500, 1E9, 10},
  {1000, 10000, 1E9, 10},
  {1000, 1E5, 1E9, 10},
};

vector<int> gen_unique_rand(int n, int l, int r) {
  unordered_set<int> t;
  while(t.size() < n) {
    t.insert(rnd.next(l, r));
  }
  return vector<int>(t.begin(), t.end());
}

void gen(string path, vector<tuple<int,int,int,int>>& data_limits) {
  ofstream ifs(path);
  if(!ifs.is_open()) {
    std::cout << "open input_file failed" << std::endl;
    return;
  }

  ifs << data_limits.size() << "\n";

  for(int t = 0; t < data_limits.size(); t++){
    auto &[n, m, M, P] = data_limits[t];
    ifs << n << ' ' << m << "\n";
    assert(m >= n - 1);
    assert(m <= n * (n - 1) / 2);
    assert(n >= 1);
    assert(n <= 2000);
    map<pair<int, int>, int> mp;
    vector<vector<int>> edges;
    for(int i = 2; i <= n; i++) {
      int x = i, y = i - 1, z = rnd.next(M / 10, M);
      if(rnd.next(1) == 0) swap(x, y);
      edges.push_back({x, y, z});
      mp[make_pair(x, y)] = mp[make_pair(y, x)] = 1;
    }
    for(int i = n; i <= m; i++) {
      int x = rnd.next(1, n);
      int y = rnd.next(1, n);
      while(y == x || (x == 1 && y == n)) y = rnd.next(1, n);
      int z = rnd.next(M / 10, M);
      if(mp.count(make_pair(x, y))) {
        i --; continue;
      }
      edges.push_back({x, y, z});
      mp[make_pair(x, y)] = mp[make_pair(y, x)] = 1;
    }
    shuffle(edges.begin(), edges.end());
    for(auto &e : edges) {
      ifs << e[0] << ' ' << e[1] << ' ' << e[2] << "\n";
    }
  }
  ifs.close();
}


int main(int argc, char* argv[]){
  registerGen(argc, argv, 1);
  gen("../test/data.in", tests);

  return 0;
}