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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int rs = 0;
    for(int i = 0, j = 0; i < n; i++){
      while(j < m && b[j] < a[i]) j ++;
      if(j < m) {
        rs ++;
        j ++;
      } else {
        break;
      }
    }
    cout << rs << endl;
  }
  return 0;
}