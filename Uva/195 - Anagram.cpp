#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

bool cond(char x, char y){
	int X = (int)x;
	int Y = (int)y;
	char a,b;
	if(X&32){
		a = x;
	}else{
		a = (char)((int)x + 32);
	} 
	if(Y&32){
		b = y;	
	}else{
		b = (char)((int)y + 32);
	} 
	
	if(a==b) return x<y;
	return a<b;

}


int main(){

	int n;
	scanf("%d",&n);
	while(n--){
		char c[1000];
		scanf("%1000s",c);
		int l = 0;
		for (int i = 0; i < 1000; ++i){
			if(c[i]=='\0') break;
			l++;
		}
		sort(c,c+l,cond);
		do{	
			for (int i = 0; i < l; ++i){
				printf("%c",c[i]);
			}
			printf("\n");
		}while(next_permutation(c,c + l,cond));
	}

	return 0;
}