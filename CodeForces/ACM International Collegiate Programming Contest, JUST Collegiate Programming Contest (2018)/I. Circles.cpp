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

#define MAX 10

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
    
    int T;
    long long a,b,d;
    cin>>T;
    while(T--){
        cin>>a>>b>>d;
        double r = (d*1.0)/2.0;
        double res = 2 * (r*r);
        printf("%.6f\n", res);
    }

	return 0;
}
