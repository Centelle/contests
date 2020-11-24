

#include <bits/stdc++.h>

using namespace std;

int rand(int a, int b){
    return a + rand() % (b + a - 1);
}

const int MAXN = 500;

string s = "abcdefghijklmnopqrstuvwxyz";

int32_t main(){
    srand(time(0));
}
