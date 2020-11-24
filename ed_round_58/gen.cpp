

#include <bits/stdc++.h>

using namespace std;

int rand(int a, int b){
    return a + rand() % (b + a - 1);
}

const int MAXN = 500;
const int MAXK = 1e9;

string s = "abcdefghijklmnopqrstuvwxyz";

int32_t main(){
    srand(time(0));
    int n = 5 * 1e5;
    for(int i = 0; i < n; ++i){
        int x = rand(1, MAXK), y = rand(1, MAXK);
        cout << x << ' '<< y << endl;
    }
}
