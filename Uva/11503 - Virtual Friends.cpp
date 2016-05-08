#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " : " << x << "\n"
#define debug2(x, y) cout << #x << " : " << x << " - " << #y << " : " << y << "\n"
#define debug3(i, n , array) for (int i = 0 ; i < n ; i++) cout << i << " : " << array[i] << "\n"
#define test() cout << "Hello World" << "\n"

#define loop(i, n) for (int i = 0 ; i < n ; i++)
#define readI(n) cin>>n
#define readS(ss) cin >> ss
#define readSS(ss1, ss2) cin >> ss1 >> ss2
#define write(n) cout<< (n) <<"\n"

#define sz(array) (sizeof(array)/sizeof(*array))
#define mset(array, value) memset(array, value , sizeof(array))
#define vi vector<int>
#define vll vector<ll>
#define mis map<int,string>
#define msi map<string,int>
#define mss map<string,string>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define MAX 200005

int F[MAX];
int root[MAX];
msi M;
int idNames,resp;

int Find(int x) {
	return F[x]==x?x:F[x]=Find(F[x]);
}

void Union(int x, int y) {
	int rootX = Find(x);
	int rootY = Find(y);
	F[rootX] = rootY;
	if(rootX != rootY) {
		root[rootY] += root[rootX];
		root[rootX] = root[rootY];
	}
	resp = root[rootY];
}

void init() { 
	idNames = 1;
	loop(i,MAX) {
		F[i] = i;
		root[i] = 1;
		M.clear();
	}
}

void setIdName(string name) {
	if(M.count(name) <= 0) 
		M[name] = idNames++;
}

int main(){
	std::ios::sync_with_stdio(false);
	int T,f;
	string ss1,ss2;
	readI(T);
	while(T--){
		init();
		readI(f);
		while(f--){
			readSS(ss1,ss2);
			setIdName(ss1);
			setIdName(ss2);
			Union(M[ss1], M[ss2]);
			write(resp);
		} 
	}
	return 0;
}


