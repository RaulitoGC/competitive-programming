#include <iostream>
#include <vector>
#include <bitset>
#include <cstring>
#include <sstream>
using namespace std;

vector<bitset<9> > v;

void generateBinary(){
	for (int i = 0; i < 513; ++i){
		bitset<9> num(i);
		//cout<<num<<" "<<num.to_ulong()<<endl; 
		v.push_back(num);
	}
}

string convert_string(long long n){
	string result="000000000";
	int x;
	for (int i = 8; i >=0 ; --i){
		stringstream ss;
		ss << n%10;
		x = ;
		result[i] = char(x);
		x/=10;
	}
	return result;
}

int main(){
	long long n,i,cont;
	generateBinary();
	int l = v.size();
	while(cin>>n){

		bitset<9> num(convert_string(n));
		cout<<"num : "<<num<<endl;
		cont = 0;
		for (i = 0; i < l; i++){
			cont++;
			cout<<v[i].to_ulong()<<" "<<num.to_ulong()<<endl;
			if(v[i].to_ulong() > num.to_ulong()) break;
		}
		cout<<cont<<endl;
	}

	return 0;
}