
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

void solve(){

}

vector<int> primeFactors(int n)
{
    // Print the number of 2s that divide n
    vector<int> ans;
    while (n % 2 == 0)
    {
        ans.push_back(2);
        n = n/2;
    }

    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            ans.push_back(i);
            n = n/i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2){
        ans.push_back(n);
    }
    return ans;
}
int32_t main(){
    int ans =0 ;
    int n; cin >> n;
    int num=-1;
    for(int i=1; i<n; ++i){
        int v = (int) primeFactors(i).size();
        if(v > ans){
            ans  = v;
            num = i;
        }
        // debug((int) primeFactors(i).size());
    }
    cout << ans << endl;
    cout << num << endl;
}
