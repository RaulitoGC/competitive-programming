#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
typedef long long ll;
typedef vector<int> vi;


ll multiply(ll a, ll b){
	return a*b;
}

ll square(ll x){
	return x*x;
}

ll potency(ll x, ll y){
	if(y==0)return 1;
	if(y == 1) return x;
	if(y%2==0) return square(potency(x,y/2));
	else return multiply(potency(x,y/2),potency(x,(y/2)+1));
}

ll process(ll n){
	if(n == 0) return 0;
	vi v,zero;
	ll result;
	int l;
	while(n){
		if(n%10 != 0) v.push_back(n%10);
		else zero.push_back(n%10);
		n/=10;
	}
	sort(v.begin(),v.end());
	l = zero.size();
	result = v[0];
	result *= potency(10,l);
	l = v.size();
	for (int i = 1; i < l; ++i){
		result*=10;
		result+=v[i];
	}
	return result;
}

int main(){

	string n,answer;
	while(cin>>n>>answer){
		if(n.size() != answer.size()){
			cout<<"WRONG_ANSWER"<<endl;
			continue;	
		}
		ll nNum,answerNum;
		stringstream ss1,ss2;
		ss1<<n;ss1>>nNum;
		ss2<<answer;ss2>>answerNum;
		nNum = process(nNum);
		if(nNum == answerNum) cout<<"OK"<<endl;
		else cout<<"WRONG_ANSWER"<<endl;
	}
	return 0;
}

