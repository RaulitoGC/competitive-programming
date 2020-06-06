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

int T, N, c, r, t;

int main(){
    
    scanf("%d",&T);
    c = 1;
    while(T--){
        scanf("%d",&N);
        for(int i = 0 ; i < N ; i++){
            scanf("%d",&t);
            if(i == N/2){
                r = t;
            }
        }
        printf("Case %d: %d\n",c,r);
        c++;
    }

	return 0;
}
