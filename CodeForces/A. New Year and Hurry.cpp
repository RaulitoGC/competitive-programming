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

const int maxMinutes = 240;

const int V[] = {5,15,30,50,75,105,140,180,225,275};


int binarySearch(int left, int rigth,int value){
	int mid; 
	while(rigth - left > 1){
		mid =(left + rigth)/2;
		if(V[mid] == value) return mid;
		if(V[mid] < value) left = mid;
		else rigth = mid; 		
	}
	
	return left;
}
	

int main(){

	int n,k,value,result;
	while(scanf("%d %d",&n,&k) == 2){
		value = maxMinutes - k;
		result = binarySearch(0,9,value)+1;
		if(k > maxMinutes - 5) printf("%d\n",0);
		else printf("%d\n",(result > n)?n:result);
		
	}	
	
	
	return 0;
}
