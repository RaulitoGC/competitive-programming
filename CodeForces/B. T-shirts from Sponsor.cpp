#include <bits/stdc++.h>

using namespace std;

int v[5];
string vss[]={"S","M","L","XL","XXL"};

void findhigh(string ss){
	int l= ss.size();
	if(ss=="S"){
		for(int i=0;i<5;i++){
			if(v[i]>0){
				cout<<vss[i]<<endl;
				v[i]--;
				break;	
			} 
		}
	}
	if(ss=="M"){
		int min=99999;
		int indx = -1;
		if(v[1]>0){
			min = 0;
			indx = 1;	
		}else{
			if(v[0]>0){
				min=1;
				indx = 0;
			}
			for(int i=2;i<5;i++){
				if(v[i]>0){
					if(abs(1-i)<=min){
						min = abs(1-i);
						indx = i;	
					} 
				}
			}
		}
		v[indx]--;	
		cout<<vss[indx]<<endl;
	}
	if(ss=="L"){
		int min=99999;
		int indx = -1;
		if(v[2]>0){
			min=0;
			indx = 2;	
		}else{
			for(int i=0;i<2;i++){
				if(v[i]>0){
					if(abs(2-i)<=min){
						min = abs(2-i);
						indx = i;	
					} 
				}
			}

			for(int i=3;i<5;i++){
				if(v[i]>0){
					if(abs(2-i)<=min){
						min = abs(2-i);
						indx = i;	
					} 
				}
			}
		} 
		
		v[indx]--;
		cout<<vss[indx]<<endl;	

	}
	if(ss=="XL"){
		int min=99999;
		int indx = -1;
		if(v[3]>0){
			min = 0;
			indx = 3;
		}else{
			if(v[4]>0){
				min=1;
				indx = 4;
			}else{
				for(int i=0;i<3;i++){
					if(v[i]>0){
						if(abs(3-i)<min){
							min = abs(3-i);
							indx = i;	
						} 
					}
				}
			}
		}
		
		v[indx]--;	
		cout<<vss[indx]<<endl;

	}
	if(ss=="XXL"){
		for(int i=4;i>=0;i--){
			if(v[i]!=0){
				cout<<vss[i]<<endl;
				v[i]--;
				break;	
			} 
		}
	}
}

int main(){

	int k;
	string ss;
	while(scanf("%d %d %d %d %d",&v[0],&v[1],&v[2],&v[3],&v[4])==5){
		scanf("%d",&k);
		for(int i=0; i<k; i++){
			cin>>ss;
			findhigh(ss);
		}
	}

	return 0;
}