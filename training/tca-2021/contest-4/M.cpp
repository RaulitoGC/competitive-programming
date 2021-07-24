#include <bits/stdc++.h>
using namespace std;
#define test() cerr<<"Hello Family"<<"\n"
#define sz(array) (int)array.size() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define popb pop_back
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define mii map<int,int>
#define pii pair<int, int>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#ifdef _DEBUG
#include "debug.cpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 0
#endif

/****************************************************************/

int a,b,c,d;

int32_t main(){

  #ifdef _LOCAL_INPUT
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
  #endif
  
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  // first = a/b

  while(cin>>a>>b>>c>>d){
    double x = a*1.0 / b*1.0;
    double r = (1.0 - (c*1.0 / d*1.0)) * (1.0 - (a*1.0 / b*1.0));
    debug(x, r);
    double res = x / (1 - r);
    debug(res);
    printf("%.12f", res);
  }

	return 0;
}
