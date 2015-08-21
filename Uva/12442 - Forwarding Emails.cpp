#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 50005
int ady[MAX];
bool visitado[MAX]; //para todo el recorrido
int cantNode[MAX];


//algoritmo estandar de DFS
int dfs( int u ){
    visitado[u] = true;
    int sumCamino = 0;
    if(ady[u]!= -1 && !visitado[ady[u]])
        sumCamino += 1 + dfs(ady[u]);
    visitado[u] = false;
    return cantNode[u] = sumCamino;
}

int main(){
    ///enumerar vertices desde 1 hasta V
    int T, N, u ,v,cases=1, n;
    scanf("%d",&T);
    while(T--){
        scanf("%d" , &N);
        memset( visitado , 0 , sizeof(visitado));
        memset( cantNode , -1 , sizeof(cantNode));
        memset( ady , -1 , sizeof(ady));
        n = N;
        while( N-- ){
            scanf("%d %d" , &u ,&v );
            ady[u] = v;
        }
        int minNodo = -1;
        int temp = -1;
        for( int i = 1 ; i <= n ; ++i ){    //recorremos todos los posibles vertices
            if(cantNode[i]==-1)
                dfs(i);
            if(cantNode[i] > temp){
                temp = cantNode[i];
                minNodo = i;
            }

        }
        printf("Case %d: %d\n" ,cases++,minNodo );
            
    }
    return 0;
}
