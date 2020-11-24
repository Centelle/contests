#include <bits/stdc++.h>

using namespace std;

// #define int long long
void solve(){
    int  x, y, n, mx, my;
    char t;
    cin >> n;
    mx = 1e9 + 2, my = 1e9 + 2;
    for(int i = 0; i < n; ++i){
        cin >> t >> x >> y;
        if(x > y) swap(x, y);
        if(t == '+') {
            mx = max(mx, x); my = max(my, y);
        } else
            if(mx <= x && my <= y) cout << "YES" << endl;
            else cout << "NO" << endl;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
