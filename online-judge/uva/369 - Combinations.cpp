#include <iostream>
#define MAX 103
using namespace std;


long long dp[MAX][MAX];
int i,j;

void init(){
	for (i = 0; i < MAX; ++i) dp[i][0] = 1;
	for (i = 0; i < MAX; ++i) dp[i][i] = 1;
	for (i = 1; i < MAX; ++i){
		for (j = 1; j < i; ++j){
			dp[i][j] = dp[i-1][j-1] +dp[i-1][j];
		}
	}

}

int main(){

	int M,N;
	init();
	while(cin>>M>>N && M && N){
		cout<<M<<" things taken "<<N<<" at a time is "<<dp[M][N]<<" exactly."<<endl;
	}

	return 0;
}
