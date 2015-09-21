#include <iostream>
#include <sstream>
using namespace std;

double convert(double x, double in_min, double in_max, double out_min, double out_max){
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


int main(){

	string HHMM;
	double h,m,resultM,resultH,temp;
	while(cin>>HHMM){
		stringstream hour,minute;
		hour<<HHMM.substr(0,2);
		hour>>h;
		minute<<HHMM.substr(3,2);
		minute>>m;
		if(h >= 12) h-=12;
		if(h == 12) h=0;
		resultH = convert(h,0,12,0,360);
		resultM = convert(m,0,60,0,360);
		temp = resultM;
		resultM = convert(resultM,0,360,0,30);
		cout<<resultH + resultM<<" "<<temp<<endl;

	}
	return 0;
}