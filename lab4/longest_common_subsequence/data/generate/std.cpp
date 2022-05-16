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
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<int> d(m + 1);
    auto f = d;
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= m; j++){
        f[j] = max(f[j - 1], d[j]);
        if(s[i - 1] == t[j - 1]) f[j] = max(f[j], d[j - 1] + 1);
      }
      d = f;
    }
    cout << d[m] << "\n";
  }
  return 0;
}