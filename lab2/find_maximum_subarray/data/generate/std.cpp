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
    int n; cin >> n;
    ll sum = 0, rs = LLONG_MIN;
    for(int i = 1; i <= n; i++){
      cin >> a[i];
      sum = max(sum + a[i], a[i]);
      rs = max(rs, sum);
    }
    cout << rs << "\n";
  }
  return 0;
}