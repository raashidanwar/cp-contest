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
  int n;
  cin >> n;
  vector <int> a(n), p(n + 1, 0);
  for (int &x : a)
    cin >> x;
  for (int i = 0; i < n; i++)
    p[i + 1] = p[i] ^ a[i];
  if (n > 60) {
    cout << 1 << "\n";
  } else {
    int ans = n - 1;
    for (int i = 0; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        for (int k = j + 1; k <= n; k++) {
          if ((p[i] ^ p[j]) > (p[j] ^ p[k])) {
            ans = min(ans, k - i - 2);
          }
        }
      }
    }
    cout << ((ans == n - 1)? -1: ans) << "\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
