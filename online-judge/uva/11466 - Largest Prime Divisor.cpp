#include <iostream>
#include <map>
#include <cmath>
using namespace std;

map<long long,long long> fact_primo(long long x){
	map<long long,long long> res;
	while(x%2==0){x/=2; res[2]++;}
	int c=3;
	while(c<=sqrt(double(x))+1)
		if(x%c==0){x/=c; res[c]++;}
		else c+=2;
	if(x>1) res[x]++;
	return res;
}

 int main(){

 	long long n;
 	while(cin>>n && n!=0){
 		if(n==1 || n==-1) cout<<"-1"<<endl;
 		else{
	 		map<long long,long long> fact;
	 		if(n<0) n=abs(n);
	 		fact = fact_primo(n);
	 		if(fact.size()==1) cout<<"-1"<<endl;
	 		else{
	 			map<long long,long long>::iterator it;
	 			it=fact.end();
	 			it--;
	 			cout<<it->first<<endl;	
	 		}
 		}

	}
 	return 0;
}
