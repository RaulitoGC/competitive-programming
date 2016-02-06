#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n,k,t;
	while(cin>>n>>k>>t){
		float a = (double)100/(double)n;
		int cont = 0;
		float i;
		for(i = a ; i<t;i+=a){
			cout<<k<<" ";
			cont++;
		}
		i-=a;
		if(n>cont){
			int rest = (n*t-100*cont);
			cout<<(int)(k*rest/100)<<" ";
			cont++;
			for(int i = 0 ; i< n-cont;i++) cout<<0<<" ";
			cout<<endl;	
		}
		
	}
	return 0;
}