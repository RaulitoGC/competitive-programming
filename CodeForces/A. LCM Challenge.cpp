#include <iostream>
#include <algorithm>
using namespace std;


long long gcd(long long a, long long b){
    return b==0? a : gcd(b,a%b);
}

long long lcm(long long a, long long b){
    return a*(b/gcd(a, b));
}

int main(){

    long long n,result;
    while(cin>>n){
        if(n<=2) result = n;
        else{
            
            result = lcm(n,lcm(n-1,n-2));
            result = max(result,lcm(n-3,lcm(n-2,n-1)));
            result = max(result,lcm(n-3,lcm(n-2,n)));
            result = max(result,lcm(n-3,lcm(n-1,n)));

        }  
        cout<<result<<endl;
    }
    return 0;
}