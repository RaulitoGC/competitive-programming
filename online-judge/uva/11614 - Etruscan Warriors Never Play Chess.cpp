#include <iostream>
using namespace std;

int main(){

	long long a,b;
	long long cont,tot,ai,bi;
	while(cin>>a>>b && (a || b)){
		cont = 0;
		bool carry = false;
		if(a > b){
			while(a){
				ai = a%10;
				bi = b%10;				
				if(ai + bi + carry> 9){
					cont++;
					carry = true;
				}else{
					carry = false;
				} 
				a/=10;
				b/=10;
			}
		}else{
			while(b){
				ai = a%10;
				bi = b%10;
				if(ai + bi + carry > 9){
					cont++;
					carry = true;
				}else{
					carry = false;
				} 
				a/=10;
				b/=10;
			}
		}
		if(cont==0) cout<<"No carry operation."<<endl;
		else
			if(cont ==1 ) cout<<cont<<" carry operation."<<endl;
			else cout<<cont<<" carry operations."<<endl;
	}

	return 0;
}