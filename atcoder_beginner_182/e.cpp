#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    auto solve = [] (){
        int h, w, n, m, ans = 0, u, v;
        cin >> h >> w >> n >> m;
        vector<vector<int>> mat(h, vector<int>(w, 0)), lit(h, vector<int>(w, 0));
        for (int i = 0; i < n; ++i) {
            cin >> u >> v; u--; v--;
            mat[u][v] = 1;
            lit[u][v] = 1;
        }
        for (int i = 0; i < m; ++i) {
            cin >> u >> v; u--; v--;
            mat[u][v] = 2;
        }
        for (int i = 0; i < h; ++i) {
            int ray = 0;
            for (int j = 0; j < w; ++j) {
                if (mat[i][j] == 1) ray = 1;
                else if (mat[i][j] == 2) ray = 0;
                lit[i][j] |= ray;
            }
            ray = 0;
            for (int j = w - 1; j >= 0; --j) {
                if (mat[i][j] == 1) ray = 1;
                else if (mat[i][j] == 2) ray = 0;
                lit[i][j] |= ray;
            }
        }
        for (int j = 0; j < w; ++j) {
            int ray = 0;
            for (int i = 0; i < h; ++i) {
                if (mat[i][j] == 1) ray = 1;
                else if (mat[i][j] == 2) ray = 0;
                lit[i][j] |= ray;
            }
            ray = 0;
            for (int i = h - 1; i >= 0; --i) {
                if (mat[i][j] == 1) ray = 1;
                else if (mat[i][j] == 2) ray = 0;
                lit[i][j] |= ray;
            }
        }
        for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) ans += lit[i][j];
        cout << ans << endl;
    };
    solve();
}
