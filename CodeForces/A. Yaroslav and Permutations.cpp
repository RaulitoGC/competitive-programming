#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	while(cin>>n){
		map<int,int> M;
		int temp;
		for(int i =0; i<n;i++){
			cin>>temp;
			M[temp]++;
		}

		int mx = -1;
		map<int,int>::iterator it;
		for(it=M.begin();it!=M.end();it++){
			if(mx < it->second) mx = it->second;
		}
		if(n%2==0){
			if(mx > n/2) cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
		}else{
			if(mx > (n/2) + 1) cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
		}

	}
	return 0;
}