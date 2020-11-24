

#include <bits/stdc++.h>

using namespace std;

int rand(int a, int b){
    return a + rand() % (b + a - 1);
}

const int MAXN = 10;
const int MAXK = 10;

string s = "abcdefghijklmnopqrstuvwxyz";

int32_t main(){
    srand(time(0));
    int n = rand(1, MAXN);
    cout << n << endl;
    for(int i = 0; i < n; ++i){
        int k = rand(1, MAXK);
        cout << k << ' ';
    }
    cout << endl;
}
