#include <bits/stdc++.h>
using namespace std;

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

#define MAX 5005

msi M;
int F[MAX];
int root[MAX];

int maxx;

int Find(int x) {
	return F[x]==x?x:F[x] = Find(F[x]);
}

void Union(int x , int y) {
	int rootX = Find(x);
	int rootY = Find(y);
	F[rootX] = rootY;
	if(rootX != rootY) {
		root[rootY] += root[rootX];
		if(root[rootY] > maxx) {
			maxx = root[rootY];
		}
	}		
}

void init(){
	loop(i,MAX){
		root[i] = 1;
		F[i] = i;
	}
}


int main() {
	std::ios::sync_with_stdio(false);
	int C, R;
	string aux1,aux2;
	while (cin >> C >> R && (C || R)) {
		maxx = 1;
		init();
		loop(i,C) {
			readS(aux1);
			M[aux1] = (i+1);
		}
		loop(i,R) {
			readSS(aux1, aux2);
			Union(M[aux1],M[aux2]);
		}
		write(maxx);
	}

	return 0;
}
	
	
	
