#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second

void solve(){
    int n, q; cin >> n >> q;
    vector<pair<int, int>> in(q);
    for(int i=0; i<q; ++i){
        cin >> in[i].fi >> in[i].se;
        in[i].fi--;
        in[i].se--;
    }
    sort(in.begin(), in.end());
    vector<int> count(n);
    for(auto p : in){
        for(int i = p.fi; i <= p.se; ++i){
            count[i]++;
        }
    }
    int ans = 0;
    for(int A = 0; A < q; ++A){
        for(int i = in[A].fi; i <= in[A].se; ++i){
            count[i] --;
        }
        vector<int> ones(n);
        int covered = 0;
        for(int i = 0; i < n; ++i){
            if(count[i] > 0){
                covered ++;
            }
            if(count[i] == 1){
                ones[i] ++;
            }
        }
        for(int i = 1; i < n; ++i){
            ones[i] += ones[i - 1];
        }
        auto sum = [&](int L, int R){
            return ones[R] - (L ? ones[L - 1] : 0);
        };

        for(int B = A + 1; B < q; ++B){
            int lost = sum(in[B].fi, in[B].se);
            ans = max(ans, covered - lost);
        }

        for(int i = in[A].fi; i <= in[A].se; ++i){
            count[i] ++;
        }
    }
    cout << ans << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
