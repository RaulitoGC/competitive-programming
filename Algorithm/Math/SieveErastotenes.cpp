#include <iostream>
#include <bitset>
#include <vector>

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


int main (){

	sieve(1000000);
	 int n;
	 while(cin>>n){
	 	if(bs[n]) cout<<" es primo!!!"<<endl;
	 	else cout<<" NO es Primo!!"<<endl;
	 }
 	
 return 0;
 }