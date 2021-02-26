#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;



int main(){

	int n;
	while(cin>>n){
		int diff,temp;
		bool flag = true;
		bool v[n];
		cin>>diff;
		memset(v,false,n);
		for (int i = 1; i < n; ++i){
			cin>>temp;
			if(abs(diff-temp)>=n){
				flag=false;
			}else{
				v[(int)abs(diff-temp)] = true;
				diff=temp;	
			} 			
		}
		
		if(!flag){
			cout<<"Not jolly"<<endl;	
		} 
		else{
			for (int i = 1; i < n; ++i){
				if(!v[i]) flag = false;
			}
			if(flag) cout<<"Jolly"<<endl;
			else cout<<"Not jolly"<<endl;
		} 
	}


	return 0;
}