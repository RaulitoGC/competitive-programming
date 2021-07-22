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

int32_t main(){

  #ifdef _LOCAL_INPUT
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
  #endif
  
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  cout << "Hello world"<< endl;
  int a = 3;
  set<int> s; s.insert(1); s.insert(1); s.insert(3); s.insert(4);
  unordered_set<int> us; us.insert(2) ;us.insert(5); us.insert(6); 
  map<int, int> m; m[2] = 2; m[3] = 4; m[9] = 4;
  unordered_map<int,int> um; um[2] = 52; um[3] = 44; um[9] = 34;

  debug(a);
  debug(s);
  debug(us);
  debug(m);
  debug(um);

	return 0;
}
