#include <iostream>
using namespace std;

int main(){

	long long n;
	while(cin>>n && n){
		if(n<=100) cout<<"f91("<<n<<") = "<<91<<endl;
		else cout<<"f91("<<n<<") = "<<n-10<<endl;
	}
	return 0;
}