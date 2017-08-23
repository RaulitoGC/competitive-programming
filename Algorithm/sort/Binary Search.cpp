#include <bits/stdc++.h>
#include <windows.h>
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
#define vf vector<float>
#define vll vector<ll>
#define msi map<int,string>
#define mss map<string,string> 

#define MAX 100005

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

ll V[MAX];

bool conditionEquals(int mid, int value){
	return  V[mid] == value;
}

bool conditionMax(ll mid, ll value){
	return V[mid] > value;
}

bool conditionMin(ll mid, ll value){
	return V[mid] < value;
}

int bsMin(int min ,int max, ll value){
	ll mid = 0;
	while(max-min > 1) {
		mid = (max + min)/2;
		debug2(min,max);
		debug(mid);
		if(conditionMin(mid,value)) min =  mid;
		else max = mid;
	}
	
	return min;
}

int bsMax(int min ,int max, ll value){
	ll mid = 0;
	while(max - min > 1){
		mid = (max + min)/2;
		debug2(min,max);
		debug(mid);
		if(conditionMax(mid,value)) max =  mid;
		else min = mid;
	}
	
	if(min + 1 == max) return -1;
	return max;
}

int bsEquals(int min ,int max, ll value){
	ll mid = 0;
	while(max - min > 1){
		mid = (max + min)/2;
		debug2(min,max);
		debug(mid);
		if(conditionEquals(mid,value)) return mid;
		
		if(conditionMin(mid,value)) min = mid;
		else max = mid;
		
	}
	return -1;
}

int main(){

	V[0] = 1;
	V[1] = 2;
	V[2] = 3;
	V[3] = 4;
	V[4] = 6;
	V[5] = 7;
	V[6] = 8;
	V[7] = 9;
	
	//cout << V[bsMax(0,7,4)] << endl;
	cout << V[bsMin(0,7,4)] << endl;
	//cout << V[bsEquals(0,7,5)] << endl;
	
	return 0;
}
