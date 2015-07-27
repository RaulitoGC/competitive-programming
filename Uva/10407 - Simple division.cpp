#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long long gcd(long long x, long long y){
	long long r;
	while (y != 0){
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}

 int main(){

 	long long n;
 	long long ni;
	long long aux;
	long long aux2;
 	
 	while(cin>>n){
 		if(n==0) break;
 		cin>>ni;
 		aux=n-ni;
		if(aux<0) aux=aux - (2*aux);
 		while(cin>>ni){
 			if(ni==0)break;
 			aux2=n-ni;
 			if(aux2<0) aux2=aux2 - (2*aux2); 
 			aux= gcd(aux,aux2);
 		}
 		cout<<aux<<endl;
 	}


 	return 0;
}
