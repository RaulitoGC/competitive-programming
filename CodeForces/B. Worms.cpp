#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

#define sz(array) (int)array.size()
#define mset(array,value) memset(array,value,sizeof(array))

#define debug(x) cout<<#x<<" : "<<x<<"\n"
#define debug2(x, y) cout << #x << " : " << x << " - " << #y << " : " << y << "\n"
#define debug3(array,n) for(int i = 0; i < n; i++) cout<< i <<" : "<<array[i]<<"\n"
#define test() cout<<"Hello world"<<"\n"
#define z() Sleep(2000)

#define loop(i,n) for(int i = 0; i < n ; i++)

#define vi vector<int>
#define vll vector<ll>
#define msi map<int,string>
#define mss map<string,string> 

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int MAX = 100005;

int V[MAX];

bool condition(int index, int value){
	return V[index] < value;
}
	

int binarySearch(int left, int rigth,int value){
	int mid; 
	while(rigth - left > 1){
		mid =(left + rigth)/2;
		if(V[mid] == value) return mid;
		if(condition(mid,value)) left = mid;
		else rigth = mid; 		
	}
	
	return left;
}
	

int main(){

	int n,ai,m,qi,index;
	while(scanf("%d",&n) == 1){
		V[0] = 1;
		for(int i = 1 ; i <= n ; i++){
			scanf("%d",&ai);
			V[i] = V[i-1] + ai;
		}
		
		scanf("%d",&m);
		for(int i = 1; i <= m ; i++){
			scanf("%d",&qi);
			index = binarySearch(0,n,qi);
			printf("%d\n",index+1);
		}
		
	}	
	
	
	return 0;
}
