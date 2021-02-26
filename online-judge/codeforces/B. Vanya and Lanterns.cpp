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

void printArray(ll V[], ll n){

	for(ll i = 0 ; i< n; i++){
		cout << V[i] << " ";
	}
	cout << endl;
}

int main(){
	
	ll n,l,dStart,dEnd;
	double result;
	while(cin >> n >> l ){
		
		ll L[n],D[n-1];
		for(int i=0; i<n ;i++){
			cin >> L[i];
		}
		sort(L, L + n);
		
		dStart = L[0];
		dEnd = l - L[n-1];
		
		if(n == 1){
			result = max(dStart,dEnd)*1.0;
			printf("%.10lf\n",result);
	
		}else{
			for(int i=0; i<n-1;i++){
				D[i] =  abs(L[i+1] - L[i]);
			}
			
			sort(D, D + n - 1);
			
			if(2*max(dStart,dEnd) > D[n-2]){
				
				result = max(dStart,dEnd)*1.0;		
			}else{
				result = D[n-2]*1.0/2.0;
				
			} 
			
			printf("%.10lf\n",result);	
		}
		
	}
	return 0;
}
