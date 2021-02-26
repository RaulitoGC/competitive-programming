#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;



long long H(long long n){
	long long res=0,i,temp=0;
	long long root = sqrt(n);
	
	for(i = 1; i <= root; ++i){
		res += i*((n/i) - (n/(i+1)));
		temp += ((n/i) - (n/(i+1)));
	}
	
	for(i = 1; i <= (n-temp); ++i){
		res += (n/i);
	}

	return res;
}


int main(){

	int T;
	cin>>T;
	long long n;
	while(T--){
		scanf("%lld",&n);
		printf("%lld\n",H(n));
	}

	return 0;
}