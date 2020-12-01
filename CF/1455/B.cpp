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
  int x;
  cin >> x;
  int k = 0, y = 0;
  while (y < x || y == x + 1) {
    y += ++k;
  }
  cout << k << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
}
