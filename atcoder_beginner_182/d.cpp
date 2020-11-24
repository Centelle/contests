
#include <bits/stdc++.h>

using namespace std;
#define int long long
void solve(){
    int n; cin >> n;
    vector<int> a(n); for(int i=0; i<n; ++i) cin >> a[i];
    vector<int> s(n);
    s[0]=a[0];
    for(int i=1; i<n; ++i)
        s[i]=s[i-1]+a[i];
    vector<int> mx(n);
    mx[0]=s[0];
    for(int i=1; i<n; ++i)
        mx[i]=max(mx[i-1],s[i]);
    int ans=0, at=0;
    for(int i=0; i<n; ++i){
        ans=max(ans,at+mx[i]);
        at+=s[i];
    }
    cout << ans << endl;
}

int32_t main(){
    solve();
}
