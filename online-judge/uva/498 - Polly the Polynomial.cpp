/* gets example */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

long square(long x){
	return x*x;
}

long potency(long base, long exp){
	if(exp==0) return 1;
	if(exp==1) return base;
	if(exp%2==0) return square(potency(base,exp/2));
	else return potency(base,exp/2)*potency(base,exp/2 + 1);
}


int main(){

	string c;
	string v;
	while(getline(cin,c)){
		istringstream iss;
		vector<long> coeff;
		vector<long> values;
		iss.str(c);
		long aux;
		while(iss>>aux){
			coeff.push_back(aux);
		}
		iss.clear();
		getline(cin,v);
		iss.str(v);
		while(iss>>aux){
			values.push_back(aux);
		}
		int l=values.size();
		
		for (int i = 0; i < l; ++i){
			long sum=0;
			long degree=coeff.size() - 1;
			long l2=coeff.size();
			for (int j = 0; j < l2; j++){
					sum += coeff[j]*potency(values[i],degree);
					degree--;
				}
			cout<<sum;
			if(i!=l-1)cout<<" ";	
		}
		cout<<endl;
		iss.clear();
	}
  	return 0;
}