
#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>

using namespace std;
#define MAX 10001

char graph[MAX][MAX];
bool visit[MAX][MAX];
int w,h;
char posInit;
int posx[] = {-1,0,1,0};
int posy[] = {0,1,0,-1};


int dfs(int x,int y){
	//cout<<x<<" "<<y<<endl;
	int result=1;
	if(visit[x][y]) result = 0;
	else{
    	visit[x][y] = true;
    	for (int i = 0; i < 4; ++i){
       	 
        	if(x+posx[i]>=0 && y+posy[i]>=0 && x+posx[i]<w && y+posy[i]<h){
            	if(graph[x+posx[i]][y+posy[i]] == posInit && !visit[x+posx[i]][y+posy[i]]){
                	result+=dfs(x+posx[i],y+posy[i]);
            	}
        	}else{
            	if(y+posy[i] == -1 && graph[x][w-1]==posInit && !visit[x][w-1]){
                	result += dfs(x,w-1);
            	}
            	if(y+posy[i]==h && graph[x][0]==posInit && !visit[x][0]){
                	result += dfs(x,0);
            	}   	 
        	}
    	}

	}
	return result;
    
}


int main(){

	int x,y;
	while(cin>>w>>h){
    	for (int i = 0; i < w; ++i){
        	for (int j = 0; j < h; ++j){
            	char c;
            	cin>>c;
            	graph[i][j] = c;
        	}
    	}
    	getchar();
    	cin>>x>>y;
    	memset(visit , 0, sizeof(visit));
    	posInit = graph[x][y];
    	int result = 0,temp = -1;
    	dfs(x,y);
    	for (int i = 0; i < w; ++i){
        	for (int j = 0; j < h; ++j){
            	if(graph[i][j]==posInit){
                	temp =  dfs(i,j);
                	if(temp>result)
                    	result = temp;
            	}

        	}
    	}
    	cout<<result<<endl;
	}

	return 0;
}
