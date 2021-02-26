
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

#define loop(n) for(int i = 0; i < n ; i++)

#define vi vector<int>
#define vll vector<ll>
#define msi map<int,string>
#define mss map<string,string> 

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int MAX = 100005;

ll V[MAX];

bool condition(ll index, ll value){
	return V[index] < value;
}
	
ll lastIndex(ll index, ll value){
	bool flag = false;
	while(V[index] == value){
		flag = true;
		index++;
	}
	return (flag)?index-1:index;
}

int binarySearch(ll left, ll rigth,ll value){
	int mid; 
	while(rigth - left > 1){
		mid =(left + rigth)/2;
		if(V[mid] == value) return lastIndex(mid,value);
		if(condition(mid,value)) left = mid;
		else rigth = mid; 		
	}
	return lastIndex(left,value);
}
int main(){

	int n,q,index;
	ll mi;
	while(scanf("%d",&n) == 1){
		for(int i = 0 ; i < n ; i++){
			cin >> V[i];
		}
		
		sort(V,V+n);
		
		scanf("%d",&q);
		for(int i = 1; i <= q ; i++){
			cin >> mi;
			if(mi < V[0]) printf("0\n");
			else if(mi >= V[n-1]) printf("%d\n",n);
			else{
				index = binarySearch(0,n-1,mi);
				printf("%d\n",index+1);
			}
		}
		
	}	
	
	
	return 0;
}
