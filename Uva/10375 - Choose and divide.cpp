#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 300
using namespace std;

int main(){

	long long p,q,r,s,l;
	long long a,b,c,temp1,temp2,result;
	int i;
	while(cin>>p>>q>>r>>s){
		a = b =1 ;
		l = min(p-q,p-r);
		cout<<" p - l : "<<(p-l)+1<<endl;
		for (i = (p-l) + 1; i <= p; ++i){
			a*= i;
		}
		cout<<"a : "<<a<<endl;
		if(p-q == l) l = r;
		else l = p-q;
		//cout<<" l :"<<l<<endl;
		for ( i = l + 1; i <= (r-s); ++i){
			b*=i;
		}
		cout<<"b : "<<b<<endl;
		temp1 = max(s,q);
		temp2 = min(s,q);
		c=1;
		for ( i = temp2 +1; i <=temp1; ++i){
			c*=i;
		}
		if(temp1==s) result = a*c/b;
		else result = (a/c)/b;

		printf("%.5f\n", result);
	}
	return 0;
}

