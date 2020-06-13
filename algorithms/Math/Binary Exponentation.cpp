#include <bits/stdc++.h>

using namespace std;

long long bp(long long base, long long exp){
    long long res = 1;
    while(exp > 0){
        if(exp&1) res = res * base;
        base = base * base;
        exp >>= 1;
    }
    return res;
}

long long bpm(long long base, long long exp, long long m){
    base %= m;
    long long res = 1;
    while(exp > 0){
        if(exp&1) res = res * base % m;
        base = base * base % m;
        exp >>= 1;
    }
    return res;
}


int main(){
    long long a =3, b = 12;
    long long res = bpm(a,b,5);
    cout << res << endl;

    return 0;
}