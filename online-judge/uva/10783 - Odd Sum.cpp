#include <iostream>
using namespace std;

int main(){

	int T,a,b,c=1;
	cin>>T;
	while(T--){
		cin>>a>>b;
		if(a==b) cout<<"Case "<<c++<<": "<<0<<endl;	
		else{
			long long result = 0;
			if(a%2==0) a++;
			for (long long i = a; i <= b ; i+=2){
				result+=i;
			}
			cout<<"Case "<<c++<<": "<<result<<endl;	
		}
	}
	return 0;
}