#include <bits/stdc++.h>
#define MAX 10000005
#define MOD 1000000007
using namespace std;

long long dp[MAX][2];

void init(){
	dp[1][0] = 0;dp[1][1] = 0;
	long long temp = 0;
	for(int i=2; i<MAX;i++){
		temp = ((dp[i-1][0]%MOD) + (dp[i-1][1]%MOD))%MOD;
		if(i%2==0) dp[i][0] = temp + 1;
		else dp[i][0] = temp - 1;
		dp[i][1] = temp*2;
		}
	}

int main(){

	long long n,result=0;
	init();
	while(cin>>n){
		ios::sync_with_stdio(false);
		result = ((((dp[n][0]%MOD)+(dp[n][1]%MOD))%MOD)*3)%MOD;
		cout<<result<<"\n";
		}
	return 0;
}
