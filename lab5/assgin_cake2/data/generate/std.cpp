#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int N = 2505;
int n, m;
PII a[N], b[N];

int main(){
  freopen("../test/data.in", "r", stdin);
  freopen("../test/data.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int T; cin >> T;
  while(T--){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    for(int i = 1; i <= m; i++) {
        cin >> b[i].first >> b[i].second;
    }
    sort(a + 1, a + n + 1, [](const PII &lth, const PII &rth) {
        return lth.second < rth.second;
    });

    sort(b + 1, b + m + 1, [](const PII &lth, const PII &rth) {
        return lth.first < rth.first;
    });

    int res = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(b[j].second > 0 && b[j].first >= a[i].first && b[j].first <= a[i].second) {
                res ++;
                b[j].second --;
                break;
            }
        }
    }

    cout << res << "\n";
  }
  return 0;
}