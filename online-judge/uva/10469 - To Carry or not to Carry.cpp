#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout<<#x<<" : "<<x<<"\n"
#define debug2(x, y) cout << #x << " : " << x << " - " << #y << " : " << y << "\n"
#define debug3(i,n,array) for(int i = 0; i < n ; i++) cout<<#array[i]<<" : "<<array[i]<<"\n"
#define test() cout<<"Hello Family"<<"\n"

#define loop(i,n) for(int i = 0; i < n ; i++)

#define sz(array) (int)array.size()
#define mset(array,value) memset(array,value,sizeof(array))

#define vi vector<int>
#define vll vector<ll>
#define msi map<int,string>
#define mss map<string,string> 

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

string tbt(unsigned int n){
    string res = "";
    while(n){
        if(n&1) res = '1' + res;
        else res = '0' + res;
        n= n>>1;
    }
    while(res.size() <= 31){
        res = '0' + res;
    }
    return res;
}


int main(){
    
    unsigned int a, b;
    while(cin>>a>>b){
        string aa = tbt(a);
        string bb = tbt(b);
        for(int i = 31 ; i >=0 ; i--){
            if(aa[i] == bb[i]) aa[i] = '0';
            else aa[i] = '1';
        }
        bitset<32> bs(aa);
        cout<<bs.to_ulong()<<endl;
    }

	return 0;
}
