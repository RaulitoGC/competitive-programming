#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

#define debug(x) cout<<#x<<" : "<<x<<"\n"
#define debug2(x, y) cout << #x << " : " << x << " - " << #y << " : " << y << "\n"
#define debug3(i,n,array) for(int i = 0; i < n ; i++) cout<<#array[i]<<" : "<<array[i]<<"\n"
#define test() cout<<"Hello world"<<"\n"
#define z() Sleep(2000)

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

bool isPrime(int n){
    assert( n > 0);

    if(n <= 1) return false;

    for( int i = 2; i*i <= n ; i++){
        cout<< i << endl;
        if(n % i == 0) return false;
    }
    return true;
}


int main(){
    
    int n;
    while(cin>>n){
        if(isPrime(n)) cout<< n <<" is Prime"<<endl;
        else cout<< n <<" is not Prime"<<endl;
    }
	return 0;
}
