#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int t,A,f,temp;
	scanf("%d",&t);
	
	while(t--){

		scanf("%d %d",&A,&f);
		for(int i=0;i<f;i++){
			if(i!=0) printf("\n");
			for(int j=1;j<=A;j++){
				temp = j;
				while(temp--){
					printf("%d",j);
				}
				printf("\n");
			}
			for(int k=A-1;k>=1;k--){
				temp = k;
				while(temp--){
					printf("%d",k);
				}
				printf("\n");
			}
			
		}
		if(t!=0)printf("\n");
	}

	return 0;
}