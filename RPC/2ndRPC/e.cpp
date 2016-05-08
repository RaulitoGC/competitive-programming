#include <bits/stdc++.h>
#define MAX  505
using namespace std;

struct Node{
	int B;
	int R;
};
	
Node Boxes[MAX][MAX];

char temp[MAX][MAX];

void init(){
	for(int i=0; i<MAX;i++){
		for(int j =0; j<MAX; j++){
				Boxes[i][j].B = 0;
				Boxes[i][j].R = 0;
				temp[i][j] = '*';
			}
		}
	}
	
void setBoxes(int N, int M){
	int i,j;
	
	if(temp[0][0]=='R') Boxes[0][0].R = 1;
	else  Boxes[0][0].B = 1;
	
	for(i = 1; i<N; i++){
		if(temp[i][0]=='R'){
			 Boxes[i][0].R = Boxes[i-1][0].R + 1;
			 Boxes[i][0].B = Boxes[i-1][0].B;
			}
		if(temp[i][0]=='B'){
			Boxes[i][0].R = Boxes[i-1][0].R;
			Boxes[i][0].B = Boxes[i-1][0].B + 1;
			} 
		}
	
	for(j = 1; j<M; j++){
		if(temp[0][j]=='R'){
			 Boxes[0][j].R = Boxes[0][j-1].R + 1;
			 Boxes[0][j].B = Boxes[0][j-1].B;
			}
		if(temp[0][j]=='B'){
			 Boxes[0][j].B = Boxes[0][j-1].B + 1;
			 Boxes[0][j].R = Boxes[0][j-1].R;
			}
		}
	
	for(int i=1; i<N;i++){
		for(int j =1; j<M; j++){
			if(temp[i][j]=='R'){
				Boxes[i][j].R = Boxes[i-1][j].R + Boxes[i][j-1].R - Boxes[i-1][j-1].R + 1;
				Boxes[i][j].B =  Boxes[i-1][j].B + Boxes[i][j-1].B - Boxes[i-1][j-1].B;
			}
			if(temp[i][j]=='B'){
				Boxes[i][j].R = Boxes[i-1][j].R + Boxes[i][j-1].R - Boxes[i-1][j-1].R;
				Boxes[i][j].B = Boxes[i-1][j].B + Boxes[i][j-1].B - Boxes[i-1][j-1].B + 1;
			}
				
			}
		}
		
	}
	
void show(int N, int M){
	cout<<endl;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cout<<Boxes[i][j].B<<" "<<Boxes[i][j].R<<"   ";
			}
			cout<<endl;
		}
		
	
	}

int main(){
	
	int T,M,N,K,xi,xf,yi,yf,contR,contB,tempR,tempB;
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%d %d %d",&N,&M,&K);
		for(int i =0;i<N;i++){
			for(int j=0; j<M; j++){
					cin>>temp[i][j];
				}
			}
		setBoxes(N,M);
		tempR = tempB = contB = contR = 0;
		for(int i=0; i<K;i++){
			cin>>yi>>xi>>yf>>xf;
			xi=N-xi;yi--;xf=N-xf;yf--;
			if(xi==xf && yi==yf){
				cout<<Boxes[xi][yi].B<<" "<<Boxes[xi][yi].R<<"\n";
				continue;
			} 
			tempB = Boxes[xi][yf].B - Boxes[xf-1][yf].B - Boxes[xi][yi-1].B + Boxes[xf-1][yi-1].B;
			tempR = Boxes[xi][yf].R - Boxes[xf-1][yf].R - Boxes[xi][yi-1].R + Boxes[xf-1][yi-1].R;
			if(xf==0 && yi!=0){
				tempB = Boxes[xi][yf].B - Boxes[xi][yi-1].B;
				tempR = Boxes[xi][yf].R - Boxes[xi][yi-1].R;
				} 	
			if(yi==0 && xf!=0){
				tempB = Boxes[xi][yf].B - Boxes[xf-1][yf].B;
				tempR = Boxes[xi][yf].R - Boxes[xf-1][yf].R;
				} 	
			if(yi==0 && xf==0){
				tempB = Boxes[xi][yf].B;
				tempR = Boxes[xi][yf].R;
				}
			cout<<tempB<<" "<<tempR<<endl;	
			contB+=tempB;
			contR+=tempR;
			
			}
			cout<<contB<<" "<<contR<<endl;
		}
	
	return 0;
	}
	
	
	
