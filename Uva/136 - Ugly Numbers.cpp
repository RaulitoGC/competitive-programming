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
	if(N>=7 && bs[N]) return false;
	vector<int> factors;
	int PF_idx = 0,PF = primes[PF_idx];
	while(PF*PF<=N){
		while(N%PF == 0){
			N/=PF;
			factors.push_back(PF);
		}
		
		PF =  primes[++PF_idx];
		cout<<PF_idx<<"  "<<PF<<endl;
		if(PF >= 7) return false;
	}
	if(N != 1) factors.push_back(N);
	return true;
}


int main(){
	sieve(20000);
	long long cont = 0;
	int i;
	primesFactor(14);
	/*	
		for (i = 1; cont != 11; ++i){

			bool flag = primesFactor(i);
			if(flag){
				cont++;
				cout<<i<<" "<<cont<<endl;
			} 
				
		}
	*/	
	cout<<i-1<<endl;
	
	return 0;
}