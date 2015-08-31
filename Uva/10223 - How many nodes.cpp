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
	cat[11] = 58786;
	cat[12] = 208012;
	cat[13] = 742900;
	cat[14] = 2674440;
	cat[15] = 9694845;
	cat[16] = 35357670;
	cat[17] = 129644790;
	cat[18] = 477638700;
	cat[19] = 1767263190;
}


int main(){
	init();
	long long n;
	bool flag;
	while(cin>>n){
		map<int, long long>::iterator i;
		for ( i= cat.begin(); i != cat.end(); ++i){
			if(n == i->second){
				cout<<i->first<<endl;
			}
		}
	}
	return 0;
}
