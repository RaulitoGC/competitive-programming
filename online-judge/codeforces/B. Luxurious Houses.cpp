#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>

#define ll long long
#define debug cout<<"ok"<<endl;
#define loop(i,n) for(int i = 0; i < n ; i++)
#define mem(array,value) memset(array,value,sizeof(array))
#define pb(x) push_back(x)
#define read(n) cin>>n;
#define write(n) cout<<n<<" ";



using namespace std;

int main(){

	ll n,vi;
	vector<ll> temp;
	vector<ll> v;
	while(cin>>n){
		v.clear();
		temp.clear();
		for (int i = 1; i <= n; ++i){
			read(vi);
			v.pb(vi);
		}
		ll maximum = -1;
		for (int i = n-1; i >= 0; --i){
			maximum = max(maximum,v[i]);
			if(maximum == v[i]) temp.pb(0);
			else temp.pb(maximum - v[i] + 1);
			
		}

		for (int i = n-1; i > 0; --i){
			write(temp[i]);
		}
		cout<<0<<endl;

	}
	return 0;
}