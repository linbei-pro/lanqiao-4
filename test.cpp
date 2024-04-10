#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "/Users/aaron/Documents/template/debug.hpp"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> d(n);
  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }
  long long low = 1, high = 1e18;
  while (low < high) {
    long long mid = (low + high) >> 1;
    int cur = 0;
    long long s = 0;
    bool bad = false;
    for (int i = 0; i < n; i++) {
      if (mid < d[i]) {
        bad = true;
        break;
      }
      if (mid >= d[i] + s) {
        s += d[i];
      } else {
        cur++;
        s = d[i];
      }
    }
    if (s) {
      cur++;
    }
    if (cur <= k && !bad) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  cout << low << '\n';
  return 0;
}
