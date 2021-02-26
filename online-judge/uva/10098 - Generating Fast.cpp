#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int t;
	scanf("%d",&t);
	while(t--){
		char c[12];
		cin>>c;
		int l = strlen(c);
		sort(c,c+l);
		do {
  		  printf("%s\n",c);
  		} while ( next_permutation(c,c+l) );
  		printf("\n");
	}
	return 0;
}