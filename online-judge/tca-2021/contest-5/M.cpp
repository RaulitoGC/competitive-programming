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

ll n,ai;

int32_t main(){

  #ifdef _LOCAL_INPUT
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
  #endif
  
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  while(cin>>n){
    vector<long long> v;
    int size = n;
    while(size--){
      cin>>ai;
      v.pb(ai);
    }

    sort(all(v), [](int const &a, int const &b){
      return a > b;
    });

    if(n == 1){
      cout << v[0] << endl;
    }else{
      long long res = 0;
      
      for(int i = 1 ; i <= n ; i *= 4){
        for(int j = 0 ; j < i ; j++ ){
          res += v[j];
        }
        debug(res);
      }
      cout << res << endl;
    }
    
  }
	return 0;
}
