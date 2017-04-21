#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout<<#x<<" : "<<x<<"\n"
#define debug2(x, y) cout << #x << " : " << x << " - " << #y << " : " << y << "\n"
#define debug3(i,n,array) for(int i = 0; i < n ; i++) cout<<#array[i]<<" : "<<array[i]<<"\n"
#define test() cout<<"Hello world"<<"\n"

#define loop(i,n) for(int i = 0; i < n ; i++)
#define read(n) cin >> n
#define readSS(ss1,ss2) cin >> ss1 >> ss2
#define write(n) cout << n << "\n"

#define sz(array) (int)array.size()
#define mset(array,value) memset(array,value,sizeof(array))
#define vi vector<int>
#define vll vector<ll>
#define msi map<int,string>
#define mss map<string,string> 

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){

	int R,N,i;
	double res;
	i = 1;
	while(cin>>R>>N){
		if(!N && !R) break;
		
	
		if(N+26*N < R){
			printf("Case %d: impossible\n",i);	
		}else{
			res = ceil((R-N)*1.0/N);
			debug(res);
			printf("Case %d: %d\n",i,(int)res);	
		}
		i++;
	}	
	return 0;
}

