#include <bits/stdc++.h>

using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  int m;
  cin >> m;
  int mx = 0, my = 0;
  while (m--) {
    char c;
    int x, y;
    cin >> c >> x >> y;
    if (x > y) swap(x, y);
    if (c == '+') {
      mx = max(mx, x);
      my = max(my, y);
    } else {
      if (mx <= x && my <= y) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}
