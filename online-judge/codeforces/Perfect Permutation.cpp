#include <iostream>
using namespace std;

int main(){

	int n;
	while(cin>>n){
		if(n&1){
			cout<<"-1";
		}else{
			for (int i = 2; i <= n; i+=2){
				cout<<i<<" "<<i-1<<" ";
			}
		}
		cout<<endl;
	}

	return 0;
}