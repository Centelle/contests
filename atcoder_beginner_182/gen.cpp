

#include <bits/stdc++.h>

using namespace std;

int rand(int a, int b){
    return a + rand() % (b + a - 1);
}

const int MAXN = 2 * (1e2);

string s = "abcdefghijklmnopqrstuvwxyz";

const int MAXK = 1e2;
int32_t main(){
    srand(time(0));
    int n = rand(1, MAXN);
    int x = rand(1, MAXN);
    cout << n << ' ' << x << endl;
    for(int i=0; i<n; ++i){
        cout << rand(1, MAXK) << ' ';
    }
    cout << endl;
}
