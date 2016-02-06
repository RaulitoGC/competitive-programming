#include <bits/stdc++.h>

using namespace std;

bool cond(int x,int y){
	return x>y;
}

int main(){

	int t,n,desc,d;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int v[n];
		for(int i =0 ; i<n;i++){
			scanf("%d",&v[i]);
		}
		sort(v,v+n,cond);
		desc = 0;
		d = n/3;
		int indx = 2;
		for(int i=0;i<d;i++){
			desc+=v[indx];
			indx+=3;
		}
		printf("%d\n",desc);
	}
	

	return 0;
}