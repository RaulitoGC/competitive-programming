#include <bits/stdc++.h>
using namespace std;

int main(){

	long long n,r1,r2,temp;
	while(cin>>n){
		if(n>0) cout<<n<<"\n";
		else{
			r1 = n%10;
			r2 = (n/10)%10;

			temp  = (n/100)*10 + r1;
			n = (n/100)*10 + r2;
			if(temp < n ) cout<<n<<"\n";
			else cout<<temp<<"\n";	
		}
	}

	return 0;
}