

#include <bits/stdc++.h>

using namespace std;

int rand(int a, int b){
    return a + rand() % (b + a - 1);
}

const int MAXN = 1e8;
const int MAXK = 1e8 ;
string s = "abcdefghijklmnopqrstuvwxyz";

int32_t main(){
    srand(time(0));
    int n = 35;
    while(n--){
        cout << rand(1, 100) << endl;
    }
}
