/*
  In the name of ALLAH
  Author : Raashid Anwar
*/
 
#include <bits/stdc++.h>
using namespace std;
 
#define int int64_t
const int M1 =  998244353;
const int M2 =  1000000007;
mt19937 rng((uint64_t)chrono::steady_clock::now().time_since_epoch().count());


void solve() {
  int n, p, k, x, y;
  string s;
  cin >> n >> p >> k >> s >> x >> y;
  vector <int> dp(n, 0);
  int ans = n * x;
  for (int i = n - 1; i >= p - 1; --i) {
    dp[i] = ((i + k) < n? dp[i + k]: 0) + (s[i] == '1'? 0: x);
    ans = min(ans, dp[i] + (i - p + 1) * y);
  }
  cout << ans << "\n";
}
 
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
}
