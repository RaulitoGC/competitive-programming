#include <bits/stdc++.h>
using namespace std;

int main(){
	
	long long n;
	long long ti;
	while(cin>>n){
		vector<long long> v;
		while(n--){
			cin>>ti;
			v.push_back(ti);
		}
		sort(v.begin(),v.end());
		long long l = v.size();
		long long temp = v[0];
		long long cont =1;
		for(int i =1 ; i<l;i++){
			if(temp <= v[i]){
				temp+=v[i];	
				cont++;
			} 
		}
		cout<<cont<<endl;
	}
	return 0;
}