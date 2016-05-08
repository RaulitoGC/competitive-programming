#include <bits/stdc++.h>

using namespace std;

double square(double x){
	return x*x;
	}
	

double distance(double x0,double y0, double xf, double yf){
	return sqrt(square(x0-xf) + square(y0-yf));
	}


int main(){
	int n,k;
	double xi,yi,tempX,tempY,result;
	while(cin>>n>>k){
		result = 0.000000;
		cin>>tempX>>tempY;
		n--;
		while(n--){
			cin>>xi>>yi;
			result+=distance(xi,yi,tempX,tempY);
			tempX = xi;
			tempY = yi;
			}
		result*=k;
		printf("%0.9f\n",result/50);
		}
	
	return 0;
	}
