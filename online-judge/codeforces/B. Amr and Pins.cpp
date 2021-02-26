#include <bits/stdc++.h>
using namespace std;

double square(double x){
	return x*x;
	}

int main(){
	ios::sync_with_stdio(false);
	int r,x0,y0,xf,yf;
	while(cin>>r>>x0>>y0>>xf>>yf){
		double distance = sqrt(square(xf-x0)+square(yf-y0));
		double lCircle = 2*r;
		cout<<ceil(distance/lCircle)<<"\n";
		}
	return 0;
}
