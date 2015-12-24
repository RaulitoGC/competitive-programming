#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	bool cond = false;
	while(cin>>n){
		int xi;
		for(int i =0;i<n;i++){
			cin>>xi;
			if(xi==1) cond = true;
		}
		if(cond)cout<<"-1"<<endl;
		else cout<<"1"<<endl;
	}
	return 0;
}