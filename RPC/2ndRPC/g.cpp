#include <bits/stdc++.h>
#define MAX 505
using namespace std;

char boxes[MAX][MAX];
bool visited[MAX][MAX];
int contB,contR;

void init(int M, int N){
		contB = 0;
		contR = 0;
		for(int i=0; i<M; i++){
			for(int j=0; j<N; j++){
					boxes[i][j] = '*';
					visited[i][j] = false;
				}
			}
	}
	
void countBR(int xi, int yi, int xf, int yf){
	//cout<<xi<<" "<<yi<<" "<<xf<<" "<<yf<<endl;
	for(int i=xi; i>=xf; i--){
		for(int j=yi; j<=yf; j++){
			//cout<<i<<" "<<j<<endl;
			if(!visited[i][j]){
				if(boxes[i][j]=='B') contB++;
				else contR++;
				visited[i][j]=true;
			}
		}
	}
}

void show(int M, int N){
	for(int i=0; i<=M; i++){
		for(int j=0; j<=N; j++){
			cout<<boxes[i][j];
		}
		cout<<endl;
	}	
}

int main(){
	
	int T,M,N,K,xi,yi,xf,yf;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d",&M,&N,&K);
		
		init(M,N);
		for(int i=0; i<M; i++){
			for(int j=0; j<N; j++){
				cin>>boxes[i][j];
			}
		}
		//show(M,N);
		
		for(int i =0;i<K;i++){
			scanf("%d %d %d %d",&xi,&yi,&xf,&yf);
			countBR(M-yi,xi-1,M-yf,xf-1);
			}
		printf("%d %d\n",contB,contR);
	}
	return 0;
}

