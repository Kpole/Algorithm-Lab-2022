#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[100010];
int main(){
  freopen("../test/data.in", "r", stdin);
  freopen("../test/data.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int T; cin >> T;
  while(T--){
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> a(n), b(m), c(p);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int j = 0; j < m; j++) cin >> b[j];
    for(int i = 0; i < p; i++) cin >> c[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<vector<int>> rs;
    for(int k = 0; k < p; k++){
      for(int i = 0, j = m - 1; i < n && j >= 0; i ++) {
        while(j >= 0 && a[i] + b[j] > c[k]) j --;
        if(j >= 0 && a[i] + b[j] == c[k]) rs.push_back({a[i], b[j], c[k]});
      }
    }

    cout << rs.size() << "\n";
    for(auto &v : rs) {
      cout << v[0] << ' ' << v[1] << ' ' << v[2] << "\n";
    }
  }
  return 0;
}