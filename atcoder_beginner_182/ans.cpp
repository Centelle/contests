#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("ouput.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    ll x;
    cin >> n >> x;

    ll a[n + 5];
    for (int i = 1; i <= n; i++) cin >> a[i];

    map<ll, ll> mp;

    for (int i = 1; i <= n; i++) {
        if (mp.find(x - a[i]) != mp.end()) {
            cout << mp[x - a[i]] << " " << i;
            return 0;
        }
        mp[a[i]] = i;
    }

    cout << "IMPOSSIBLE";

    return 0;
}