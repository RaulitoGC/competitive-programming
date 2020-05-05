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

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int floorSqrt(int x) {     
    if (x == 0 || x == 1)  return x; 
  
    int l = 1, r = x >> 1, ans;    
    while (l <= r)  {
        int mid = l + ((r - l) >> 1); 
  
        if (mid * mid == x) return mid; 
  
        if (mid*mid < x) { 
            l = mid + 1; 
            ans = mid; 
        }  
        else r = mid-1;  
    } 
    return ans; 
}


int main(){

	int a;
	while(cin>>a){
		int temp = floorSqrt(a);
		cout<< temp << endl;
	}
	return 0;
}
