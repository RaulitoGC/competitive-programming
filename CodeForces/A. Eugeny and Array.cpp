#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n,m,temp;
	int l,r,aux;
	scanf("%d %d",&n,&m);

		map<int,int> M;
		while(n--){
			cin>>temp;
			M[temp]++;
		}
		while(m--){
			scanf("%d %d",&l,&r);
			aux = r-l + 1;
			if(aux%2!=0){
				printf("0\n");	
			}else{
				if(M[-1]>=aux/2 && M[1]>=aux/2) printf("1\n");
				else printf("0\n");
			}
		}

	return 0;
}