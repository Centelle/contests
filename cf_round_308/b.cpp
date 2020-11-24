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

template<typename T>
int sum(vector<T> a){
    int s = 0;
    for(int i = 0; i < (int) a.size(); ++i){
        s += a[i];
    }
    return s;
}

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

const int K = 9;
int digits (int n){
    int count = 0;
    while(n){
        count ++;
        n /= 10;
    }
    return count;
}

int pow(int a, int b){
    int res = 1;
    for(int i = 1; i <= b; ++i){
        res *= a;
    }
    return res;
}
void solve(){
    int n; cin >> n;
    string s = "";
    int m = n;
    while(m){
        int p = m % 10;
        s += char(p + '0');
        m /= 10;
    }
    reverse(s.begin(), s.end());
    vector<int> count(K + 1);
    for(int i = 1; i <= K; ++i){
        count[i] = i * (pow(10, i) - pow(10, i - 1));
    }
    debug(count, s);
    int ans = 0;
    int len = sz(s);
    for(int i = 0; i < len; ++i){
        int D = s[i] - '0';
        debug(D);
        int cur = 0;
        for(int j = 1; j <= len - i - 1; ++j){
            cur += count[j];
        }
        cur -= ((pow(10, len - i) * 9) - (D * pow(10, len - i))) * count[len - i];
        debug(cur);
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen(".in", "r", stdin); freopen(".out", "w", stdout);
    solve();
}
