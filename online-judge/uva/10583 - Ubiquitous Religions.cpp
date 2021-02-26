#include <bits/stdc++.h>
#define MAX 50005

using namespace std;

vector<int> F (MAX);
int numComponentes;

void init(int n){
	for ( int i = 1 ; i <= n ; i++ ) {
		F[i] = i;
	}
}

int Find(int x){
	return F[x]==x?x:F[x] = Find(F[x]);
}

void Union(int x, int y){
	F[Find(x)] = Find(y);
}

int getNumberConnectedComponents( int n ){
    numComponentes = 0;
    for( int i = 1 ; i <= n ; ++i ){
        if( F[ i ] == i ){    
            numComponentes++;
        }
    }
    return numComponentes;
}

int main(){
	std::ios::sync_with_stdio(false);
	int T,N,M,A,B;
	T=1;
	while (cin >> N >> M && (N || M ) ) {
		init(N);
		for ( int i = 0 ; i < M ; i++ ) { 
			cin >> A >> B;
			Union(A,B);
		}
		cout<<"Case "<<T++<<": "<<getNumberConnectedComponents(N)<<"\n";
	} 
	return 0;
}
