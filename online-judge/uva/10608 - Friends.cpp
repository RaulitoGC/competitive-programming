#include <bits/stdc++.h>
#define MAX 30005

using namespace std;

vector<int> F (MAX);
int root[ MAX ]; 
int numVertices[ MAX ];
int numComponentes;

void init(int n) {
	memset( numVertices , 0 , sizeof( numVertices ) );
	memset( root , 0 , sizeof( root ) );
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

void getNumberConnectedComponents( int n ){
    numComponentes = 0;
    for( int i = 1 ; i <= n ; ++i ){
        if( F[ i ] == i ){    
            root[ numComponentes++ ] = i;  
        }
    }
}


int getMaxNumberNodes( int n ){
    int maxNumNodes = -1;  
    for( int i = 1 ; i <= n ; ++i ){
        numVertices[ Find( i ) ]++;                   
    }
    
    for( int i = 0 ; i < numComponentes ; ++i ){
        maxNumNodes = max( numVertices[ root[ i ] ] , maxNumNodes );
    }
    
    return maxNumNodes;
}



int main(){
	std::ios::sync_with_stdio(false);
	int T,N,M,A,B;
	cin >> T;
	while ( T-- ){
		cin >> N >> M;
		init(N);
		for ( int i = 0 ; i < M ; i++ ) { 
			cin >> A >> B;
			Union(A,B);
		}
		getNumberConnectedComponents(N);
		cout<< getMaxNumberNodes(N)<<"\n";
	} 
	return 0;
}
