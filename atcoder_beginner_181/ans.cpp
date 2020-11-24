#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
void chmin(int& a, int b) {
    if (a > b) {
        a = b;
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> H(N);
    for (auto& h : H) cin >> h;
    vector<int> W(M);
    for (auto& w : W) cin >> w;
    sort(H.begin(), H.end());
    vector<int> sum1((N + 1) / 2), sum2((N + 1) / 2);
    for (int i = 0; i + 1 < N; i += 2) sum1[i / 2 + 1] = sum1[i / 2] + H[i + 1] - H[i];
    for (int i = N - 2; i > 0; i -= 2) sum2[i / 2] = sum2[i / 2 + 1] + H[i + 1] - H[i];
    int ans = INF;
    for (int w : W) {
        int x = lower_bound(H.begin(), H.end(), w) - H.begin();
        if (x & 1) x ^= 1;
        chmin(ans, sum1[x / 2] + sum2[x / 2] + abs(H[x] - w));
#ifdef LOCAL
        cout << "sum1[x / 2] + sum2[x / 2] + abs(H[x] - w): " << sum1[x / 2] + sum2[x / 2] + abs(H[x] - w) << endl;
#endif
    }
    cout << ans << endl;
}
