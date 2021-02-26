#include <bits/stdc++.h>
using namespace std;

int main(){

	string ss;
	int n,m,temp,l,r;

	while(cin>>ss){
		scanf("%d",&m);
		n = ss.size();
		int v[n+2];
		temp = 0;
		v[1] = 0;
		for(int i=1;i<n;i++){
			if(ss[i]==ss[i-1]) temp++;
			v[i+1] = temp;
		}
		while(m--){
			scanf("%d %d",&l,&r);
			printf("%d\n",v[r] - v[l]);
		}
	}


	return 0;
}