#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	
	long long n;
	long long a;

	while(cin>>n){
		long long resp=0;
		for (int i = 0; i < n; ++i){
			cin>>a;
			resp = max(resp,a);
		}
		cout<<resp<<endl;

	}

	return 0;
}