#include <bits/stdc++.h>
using namespace std;

int main(){

	int t,s;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&s);
		int v[s],i,sum;
		for(i =0 ; i<s;i++){
			scanf("%d",&v[i]);
		}
		sort(v,v+s);
		sum=0;
		for(i=0;i<s;i++){
			sum+=abs(v[s/2]-v[i]);
		}
		printf("%d\n",sum);
	}
	return 0;
}