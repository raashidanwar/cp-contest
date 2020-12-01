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
  vector <int> x(4), y(4), a(4);
  for (int i = 0; i < 4; i++)
    cin >> x[i] >> y[i];
  int ans = M2 * M2;
  for (int i = 0; i < 4; i++)
    a[i] = i;
  auto get = [&](vector <int>& a) {
    sort(a.begin(), a.end());
    int sum = 0;
    for (int i = 0; i < 4; i++)
      sum += abs(a[i] - a[1]);
    return sum;
  };
  
  set <int> d;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) {
      d.insert(x[i] - x[j]);
      d.insert(y[i] - y[j]);
    }
  
  do {
    for (int d0 : d) {
      vector <int> xi(4), yi(4);
      for (int i = 0; i < 4; i++) {
        xi[i] = x[a[i]];
        yi[i] = y[a[i]];
      }
      xi[2] -= d0;
      xi[3] -= d0;
      yi[1] -= d0;
      yi[2] -= d0;
      ans = min(ans, get(xi) + get(yi));
    }
  } while (next_permutation(a.begin(), a.end()));
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
