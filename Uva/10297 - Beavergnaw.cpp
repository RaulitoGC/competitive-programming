#include <bits/stdc++.h>
using namespace std;

int main(){

	double D,V;
	double pi = 2*acos(0);
	while(scanf("%lf %lf",&D,&V)==2 && (D && V)){
		printf("%.3f\n", pow((D*D*D) - (6*V/pi) ,1/3.));
	}




	return 0;
}