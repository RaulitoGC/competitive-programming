#include <bits/stdc++.h>
using namespace std;

#define pi acos(-1)

#define debug(x) cout << #x <<" : " << x << "\n";
#define debug2(x,y) cout << #x <<" : " << x << " - " << #y << " : " << y << "\n";
#define debug3(i,n,array) for (int i = 0 ; i < n ; i++) cout << i << " : " << array[i] <<"\n";
#define test() cout << "Hello World" << "\n";

#define loop(i,n) for (int  i = 0 ; i < n ; i++)
#define readI(n) cin>>n
#define readS(ss) cin >> ss;
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

double square(double n) {
	return n*n;
}

int main(){ 
	
	double d,h,v,e,area,aux1,aux2;
	while (cin >> d >> h >> v >> e) {
		area = pi*square(d/2);
		aux1 = v/area;
		aux2 = e - aux1;
		if (aux2 > 0) {
			cout << "NO"<<"\n";
		} else {
			aux2*=-1;
			cout<< "YES"<<"\n";
			printf("%.12f\n",h/aux2);
		} 
	}
	
	return 0;
}
