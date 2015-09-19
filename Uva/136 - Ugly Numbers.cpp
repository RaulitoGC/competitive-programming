#include <iostream>
#include <vector>
#include <bitset>
#include <cstdio>
using namespace std;

bitset<10000010> bs;
vector<int> primes; 
long long _sieve_size;

void sieve(long long uppebound){

	_sieve_size =  uppebound +1;

	bs.set();
	bs[0] = bs[1] = 0;
	for (long long i = 2; i <= _sieve_size; ++i){
		if(bs[i]){
			for (long long j = i*i; j <= _sieve_size; j+=i)
				bs[j] = 0;
			
			primes.push_back((int)i);
		}
	}
}

bool primesFactor(long long N){
	if(n >= 7 && bs[n]) return false;

	vector<int> factors;
	int PF_idx = 0,PF = primes[PF_idx];
	while(PF*PF<=N){
		while(N%PF == 0){
			N/=PF;
			factors.push_back(PF);
		}
		PF =  primes[++PF_idx];
		if(PF>=7) return false;
	}
	if(N != 1) factors.push_back(N);
	if(N >= 7) return false;
	return true;
}


int main(){

	long long cont = 0,i;
	for (i = 1; cont <= 15; ++i){
		if(primesFactor(i)){
			cout<<cont<<" "<<i<<<endl;
		 	cont++;	
		}
	}


	return 0;
}