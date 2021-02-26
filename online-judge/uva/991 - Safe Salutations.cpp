#include <iostream>
#include <map>
using namespace std;

map<int, long long> cat;

void init(){
	cat[1] = 1;
	cat[2] = 2;
	cat[3] = 5;
	cat[4] = 14;
	cat[5] = 42;
	cat[6] = 132;
	cat[7] = 429;
	cat[8] = 1430;
	cat[9] = 4862;
	cat[10] = 16796;
}


int main(){
	init();
	long long n;
	bool flag=false;
	while(cin>>n){
		if(flag)cout<<endl;
		flag=true;
		cout<<cat[n]<<endl;
	}
	return 0;
}
