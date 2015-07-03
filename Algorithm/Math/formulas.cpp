#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

double h[]={0.1,0.01,0.001,0.0001,0.00001,0.000001,0.0000001,0.00000001,0.000000001};

double funcion(double x, double y){
	return (x*y)/(x+y);
}

double first(double x, int i){
	return (funcion(x+h[i],1) - funcion(x,1))/h[i];
}

double second(double x, int i){
	return (funcion(x,1) - funcion(x - h[i],1))/h[i];
}

double third(double x, int i){
	return (funcion(x+h[i],1) - funcion(x-h[i],1))/(2*h[i]);
}


int main(){

	double x;
	int y;
	while(cin>>x>>y){
		printf("%0.9f\n", first(x,y));
		printf("%0.9f\n", second(x,y));
		printf("%0.9f\n", third(x,y));	
	}

	return 0;
}