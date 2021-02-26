#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>

#define ll long long;
#define debug cout<<"ok"<<endl;
#define loop(i,n) for(int i = 0; i < n ; i++)
#define mem(array,value) memset(array,value,sizeof(array))
#define pb(x) push_back(x)
#define read(n) scanf("%d",&n)

using namespace std;

int main(){

	int a,b;
	while(cin>>a>>b){
		cout<<min(a,b)<<" "<<abs(a-b)/2<<endl;
	}
	return 0;
}