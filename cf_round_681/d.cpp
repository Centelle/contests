
#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) {
    return '"' + s + '"';
}
string to_string(const char* s) {
    return to_string((string) s);
}
string to_string(bool b) {
    return (b ? "true" : "false");
}
string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}
template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
template<typename T>
void read(T& val){
    cin >> val;
}
template<typename T>
void read(vector<T>& a){
    for(int i = 0; i < (int)a.size(); ++i){
        read(a[i]);
    }
}
template<typename Head, typename... Tail>
void read(Head& H, Tail&... T){
    read(H);
    read(T...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
#define vec vector
#define i64 long long
#define endl '\n'
#define sz(x) (int)(x).size()
#define times(n) for(int i = 0; i < (n); ++i)
#define bits(x) __builtin_popcount(x)
#define int long long

int query_number = 1;
void print_query(){
#ifdef LOCAL
    cout << "Query #" << query_number++ << ": ";
#endif
}
int test_case_number = 1;
void print_case(){
#ifdef LOCAL
    cout << "Case #" << test_case_number++ << ": ";
#endif
}

int n;
void solve(){
    cin >> n;
    vector<int> a(n), b(n), c(n);
    read(a);
    int m = a[0];
    for(int i=0; i<n; ++i){
        int& v = a[i];
        b[i] = min(m, a[i]);
        c[i] = a[i] - b[i];
        m = b[i];
    }
    int t = b[n - 1];
    b[n - 1] = 0;
    c[n - 1] += t;
    for(int i = n - 2; i >= 0; --i){
        int t = b[i];
        int k = max(b[i + 1], t + c[i] - c[i + 1]);
        b[i] = k;
        c[i] += (t - k);
    }
    bool fine = 1;
    for(int i=0; i<n-1; ++i){
        if(b[i] < b[i + 1]) fine = 0;
        if(c[i] > c[i + 1]) fine = 0;
        if(b[i] < 0 || c[i] < 0) fine = 0;
    }
    if(fine)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        print_case();
        solve();
    }
}
