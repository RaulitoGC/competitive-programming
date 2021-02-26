#include <bits/stdc++.h>

using namespace std;

int aux[] = {1,2,3,4,5,6,8,9,10,12,15,18,20,24,30,36,40,45,60,72,90,120,180,360};
set<int> angles;

void init(){
	for(int i =0; i<24;i++){
		angles.insert(((aux[i]-2)*180)/(aux[i]));
		}
	}

int main(){
	
	int t,a;
	init();
	while(scanf("%d",&t)==1){
		while(t--){
			scanf("%d",&a);
			if(angles.count(a)==1) printf("YES\n");
			else printf("NO\n");
			}
		
		}
	return 0;
	}
