#include <bits/stdc++.h>
using namespace std;

long long signFunction(long long x,long long y,long long A, long long B, long long C){
	if((A*x + B*y + C) == 0) return 0;
	if((A*x + B*y + C) < 0) return -1;
	else return 1;
	}


int main(){
	
	ios::sync_with_stdio(false);
	long long x1,y1,x2,y2,n,a,b,c,cont;
	while(cin>>x1>>y1){
		cin>>x2>>y2;
		cin>>n;
		cont=0;
		while(n--){
			cin>>a>>b>>c;
			if(signFunction(x1,y1,a,b,c)==0 ||  signFunction(x2,y2,a,b,c)==0) continue;
			if(signFunction(x1,y1,a,b,c)!=signFunction(x2,y2,a,b,c)) cont++;
			}
			cout<<cont<<"\n";
		}
	return 0;
	}
