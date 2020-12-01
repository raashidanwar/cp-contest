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
  int n, x;
  cin >> n >> x;
  vector <int> a(n);
  for (int &i : a)
    cin >> i;
  map <pair <int, int>, int> dp, new_dp;
  dp[{0, x}] = 0;
  for (int &i : a) {
    for (auto it : dp) {
      if (it.first.first <= max(it.first.second, i)) {
        if (it.first.second < i && it.first.first <= it.first.second) {
          if (new_dp.find({it.first.second, i}) == new_dp.end()) {
            new_dp[{it.first.second, i}] = it.second + 1;
          } else {
            new_dp[{it.first.second, i}] = min(new_dp[{it.first.second, i}], it.second + 1);
          }
        }
        if (i >= it.first.first) {
          if (new_dp.find({i, it.first.second}) == new_dp.end()) {
            new_dp[{i, it.first.second}] = it.second;
          } else {
            new_dp[{i, it.first.second}] = min(new_dp[{i, it.first.second}], it.second);
          }
        }
      }
    }
    dp = new_dp;
    new_dp.clear();
  }
  if (dp.empty()) {
    cout << -1 << "\n";
  } else {
    int ans = dp.begin()->second;
    for (auto it : dp)
      ans = min(ans, it.second);
    cout << ans << "\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
}
