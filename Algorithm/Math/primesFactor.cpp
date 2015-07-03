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

vector<int> primesFactor(long long N){
	
	vector<int> factors;
	int PF_idx = 0,PF = primes[PF_idx];
	while(PF*PF<=N){
		while(N%PF == 0){
			N/=PF;
			factors.push_back(PF);
		}
		PF =  primes[++PF_idx];
	}
	if(N != 1) factors.push_back(N);
	return factors;
}


int main(){
	sieve(1000000);
	long long n;
	while(cin>>n){
		vector<int> v = primesFactor(n);
		for(vector<int>::iterator i= v.begin(); i!=v.end(); i++)
			printf("%d ", *i);
		cout<<endl;	
	}
	return 0;
}