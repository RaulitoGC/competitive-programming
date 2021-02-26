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

int square(int x){
	return x*x;
}

int main(){

	int a,b,n,x,y,v;
	double resp = 300.00000000000000000000,temp;
	scanf("%d %d %d",&a,&b,&n);
	while(n--){
		scanf("%d %d %d",&x,&y,&v);
		temp = sqrt(square(a-x) + square(b-y))/v;
		if(temp < resp) resp = temp;
	}

	printf("%.20f\n",resp);

	return 0;
}
