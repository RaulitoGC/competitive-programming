#include <bits/stdc++.h>
#include <windows.h>
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

int main(){
	
	int n = 4;
	int arr[n] = {1,4,3,0};
	
//	int n = 7;
//	int arr[n] = {3,5,7,2,1,0,4};
	
	int sum = 0;
	int realSum = (n*(n+1))/2;
	for(int i = 0 ; i < n ; i++){
		sum += arr[i];
	}
	
	cout << realSum - sum << endl;
	
	return 0;
}
