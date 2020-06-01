#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cout<<#x<<" : "<<x<<"\n"
#define debug2(x, y) cout << #x << " : " << x << " - " << #y << " : " << y << "\n"
#define debug3(n,array) for(int i = 0; i < n ; i++) cout<<#array[i]<<" : "<<array[i]<<"\n"
#define test() cout<<"Hello world"<<"\n"
 
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
 
long long x,y,z;
 
long long square(long long x){
    return x*x;
}
 
bool valid(int p,int q){
    return (1.0*(p-q)) > (1.0*sqrt(2)*q);
}
 
bool valid2(int p, int q){
    return (1.0*(p-q)) < (1.0*sqrt(2)*q);
}
 
int main(){
	long long n;
	while(cin>>n){
        if(n == 1){
            printf("No, please let me go\n");
            continue;
        }
        vector<long long> v;
        if(n%2 == 0){
            n /= 2;
            for (int i=1; i <= sqrt(n); i++){ 
                if (n%i==0) { 
                    v.push_back(i);
                    v.push_back(n/i); 
                }
            }
 
            int i, size = sz(v), p,q;
            for(i = 0; i < size ; i+=2){
                if(valid(v[i+1],v[i])) break;
            }
            if(i < size){
                printf("Yes, YOU CAN\n");
            }else{
                printf("No, please let me go\n");
            }
        }else{
            for (int i=1; i <= sqrt(n); i++){ 
                if (n%i==0) {
                    v.push_back(i);
                    v.push_back(n/i); 
                }
            }
            
            int i, size = sz(v), p,q;
            for(i = 0; i < size ; i+=2){
                p = (v[i]+v[i+1])/2;
                q = v[i+1] - p;
                if(valid2(p,q)) break;
            }
 
            if(i < size){
                printf("Yes, YOU CAN\n");
            }else{
                printf("No, please let me go\n");
            }
        } 
        
    }
		
	return 0;
}