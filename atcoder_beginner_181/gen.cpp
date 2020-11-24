

#include <bits/stdc++.h>

using namespace std;

int rand(int a, int b) {
    return a + rand() % (b + a - 1);
}

const int MAXN = 1e5;
const int MAXK = 1e9;
string s = "abcdefghijklmnopqrstuvwxyz";

int32_t main() {
    srand(time(0));
    int n = rand(2, MAXN);
    if(n %2 == 0){
        n += 1;
    }
    int m = rand(1, MAXN);
    cout << n << ' ' << m << endl;
    for (int i = 0; i < n; ++i) {
        cout << rand(1, MAXK) << ' ';
    }
    cout << endl;
    for (int i = 0; i < m; ++i) {
        cout << rand(1, MAXK) << ' ';
    }
    cout << endl;
}
