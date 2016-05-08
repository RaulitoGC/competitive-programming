#include <bits/stdc++.h>
using namespace std;

#define pi acos(-1)

#define debug(x) cout << #x <<" : " << x << "\n";
#define debug2(x,y) cout << #x <<" : " << x << " - " << #y << " : " << y << "\n";
#define debug3(i,n,array) for (int i = 0 ; i < n ; i++) cout << i << " : " << array[i] <<"\n";
#define test() cout << "Hello World" << "\n";

#define loop(i,n) for (int  i = 0 ; i < n ; i++)
#define read(n) cin >> n
#define readSS(ss1,ss2) cin>> ss1 >> ss2
#define write(n) cout<< (n) << "\n"

#define sz(array) (int)array.size()
#define mset(array, value) memset(array, value, sizeof(array))
#define vi vector<int>
#define vll vector<ll>
#define mis map<int,string>
#define mss map<string,string>
#define msi map<string,int>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main() {
	
	ll n,aux1,aux2;
	while (read(n)) {
		vll V(n);
		loop(i,n) {
			read(V[i]);
		}
		sort(V.begin(),V.end());
		aux1 = 0;
		aux2 = V[n-1];
		loop (i,n-1) {
			if(aux2 < aux1) {
				aux2 +=V[i];
			} else {
				aux1 +=V[i];
			}
		}
		write(abs(aux2-aux1)+1);
	}
	return 0;
}
