#include <iostream>
#include <cmath>
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

long long multiply(long long a, long long b){
	return a*b;
}

long long square(long long x){
	return x*x;
}

long long potency(long long x, long long y){
	if(y==0)return 1;
	if(y == 1) return x;
	if(y%2==0) return square(potency(x,y/2));
	else return multiply(potency(x,y/2),potency(x,(y/2)+1));
}


int main(){

	int N,l,i,j;
	long long low,high,cont;
	sieve(10000010);
	while(cin>>N){
		while(N--){
			cin>>low>>high;
			cont = 0;
			l = sqrt(high);
			vector<int> temp;
			for (i = low; i <= l; i++){
				if(bs[i]) temp.push_back(i);
			}
			l= temp.size();
			bool flag;
			for (i = 0; i < l; ++i){
				flag = true;
				j = 2;
				while(potency(temp[i],j) < high){
					cont++;
					j++;
				}
			}
			cout<<cont<<endl;
		}
	}

	return 0;
}
