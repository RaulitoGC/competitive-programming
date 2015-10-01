#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define MAX 20005 
#define Node pair< int , long long > 
#define INF 1<<30 
#define read(n) scanf("%d",&n);
#define DEBUG printf("OK /n");

struct cmp {
    bool operator() ( const Node &a , const Node &b ) {
        return a.second > b.second;
    }
};

vector< Node > ady[MAX]; 
int dist[MAX];      
bool visited[MAX];      
priority_queue<Node,vector<Node> , cmp> Q;                           
int n;

void init(){
    for( int i = 0 ; i <= n ; ++i ){
        dist[i] = INF;  
        visited[i] = false;
        ady[i].clear();   
    }
    
}

void relaxation( int actual , int adyacente , int peso ){
    if( dist[actual]+peso < dist[ adyacente]){
        dist[adyacente] = dist[actual] + peso; 
        Q.push(Node(adyacente , dist[adyacente])); 
    }
}


void dijkstra( int first ){
    Q.push(Node(first,0));
    dist[first] = 0;  
    int actual , adyacente , peso;
    while(!Q.empty()){                   
        actual = Q.top().first;          
        Q.pop();                         
        if(visited[actual]) continue; 
        visited[actual] = true;
        for( int i = 0 ; i < ady[actual].size() ; ++i ){
            adyacente = ady[actual][i].first;   
            peso = ady[actual][i].second;        
            if(!visited[adyacente]){       
                relaxation( actual , adyacente , peso ); 
            }
        }
    }
}


int main(){
    int N,m,S,T,u,v,w;
    read(N)
    while(N--){
        scanf("%d %d %d %d",&n,&m,&S,&T); //S:origin - T: end
        init();
        for (int i = 0; i < m; ++i){
            scanf("%d %d %d",&u,&v,&w);
            ady[u].push_back( Node(v,w)); 
            ady[v].push_back( Node(u,w)); 
        }
        dijkstra(S); // call Dijsktra with origin = S
        printf("%d \n",dist[T]); //print distance for node T:end   
        
    }
    return 0;
}