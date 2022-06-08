#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PLI = pair<ll, int>;

int main(){
  freopen("../test/data.in", "r", stdin);
  freopen("../test/data.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int T; cin >> T;
  while(T--){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> e;
    vector<int> w(n + 1), f(n + 1);
    iota(f.begin(), f.end(), 0);
    function<int(int)> get = [&](int x) { return x == f[x] ? x : f[x] = get(f[x]); };

    for(int i = 0; i < n; i++) {
      cin >> w[i];
      e.push_back({i, n, w[i]});
    }

    for(int i = 0; i < m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      e.push_back({u, v, w});
    }
    
    sort(e.begin(), e.end(), [&](vector<int>& a, vector<int>& b){
      return a[2] < b[2];
    });
    m = e.size();
    long long res = 0;
    for(int i = 0; i < m; i++) {
      int x = e[i][0], y = e[i][1], z = e[i][2];
      if(get(x) == get(y)) continue;
      f[get(x)] = get(y);
      res += z;
    }
    cout << res << "\n";
  }
  return 0;
}