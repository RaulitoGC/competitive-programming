#include <bits/stdc++.h>
#define MAX  100000
using namespace std;

int main(){

	long long n,sum;
	string ss;
	bool flag;
	while ( cin >> n ) {
		long long v[n];
		cin >> ss;
		for ( int i = 0 ; i< n ; i++){
			cin >> v[i];
		}
		flag = false;
		sum = 0;
		for ( int i = 0; ; ){
			if ( sum > MAX && !( i < 0 || i >= n) ) {
				flag = false;
				break;
			}
			if( ( i < 0 || i >= n) && !( sum > MAX ) ) {
				flag = true;
				break;
			}
			if ( ss[i] == '>' ) {
				i += v[i];
			} else {
				i -= v[i];
			}		
			sum++;
		}
		if(flag) cout<<"FINITE\n";
		else cout<<"INFINITE\n";

	}
}
