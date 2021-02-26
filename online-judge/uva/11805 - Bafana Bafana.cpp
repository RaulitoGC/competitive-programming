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

int T, N ,K ,P,c,t;

int main(){
    
    scanf("%d",&T);
    c = 1;
    while(T--){
        scanf("%d %d %d",&N, &K , &P);
        t = K + P%N;
        if(t > N){
            printf("Case %d: %d\n", c, t%N);
        }else{
            printf("Case %d: %d\n",c, t);
        }
        c++;
    }

	return 0;
}
