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
    vector<vector<pair<int, int>>> e(n + 1);
    for(int i = 0; i < m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      e[u].push_back(make_pair(v, w));
      e[v].push_back(make_pair(u, w));
    }
    priority_queue<PLI, vector<PLI>, greater<PLI>> q;
    vector<ll> d(n + 1, LLONG_MAX);
    vector<int> v(n + 1, 0);
    q.push({0, 1});
    d[1] = 0;
    while(q.size()) {
      int x = q.top().second; q.pop();
      if(v[x]) continue;
      v[x] = 1;
      for(auto &[y, z] : e[x]) {
        if(d[y] > d[x] + z) {
          d[y] = d[x] + z;
          q.push({d[y], y});
        }
      }
    }
    cout << d[n] << "\n";
  }
  return 0;
}