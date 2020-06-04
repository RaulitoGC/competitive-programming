/***************************************************************
Algoritmo: Classic Sieve of Eratostenes
Type: Sieve of Eratostenes
Author: Raul Guzman
Time Complexity : (n)LogLog(n)
Space Complexity : O(n) using array / O(n/8) using bitset
****************************************************************/

#include <iostream>
#include <bitset>
#include <vector>

#define debug3(n,array) for(int i = 0; i < n ; i++) cout<<array[i]<<" "

using namespace std;
 
bitset<10000010> bs;
vector<int> primes; 
long long _sieve_size;

// N/2 faster but does not mark odds number as no prime
// void sieve(long long uppebound){

// 	_sieve_size =  uppebound +1;
// 	bs.set();
// 	bs[0] = bs[1] = 0;
// 	bs[2] = 1;
// 	for (long long i = 3; i <= _sieve_size; i+=2){
// 		if(bs[i]){
// 			for (long long j = i*i; j <= _sieve_size; j+=i)
// 				bs[j] = 0;
			
// 			primes.push_back((int)i);
// 		}
// 	}
// }

// Marks all the number if it is prime or not
void sieve(long long uppebound){

	_sieve_size =  uppebound +1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (long long i = 2; i <= _sieve_size; i++){
		if(bs[i]){
			for (long long j = i*i; j <= _sieve_size; j+=i)
				bs[j] = 0;
			
			primes.push_back((int)i);
		}
	}
}


int main (){

	sieve(100);
	int n;
	debug3(100, bs); 
 	cout <<endl;
	for(int i = 0 ; i < 100 ; i++){
		cout << i <<" -- " <<bs[i]<<endl;
	}
 	return 0;
 }