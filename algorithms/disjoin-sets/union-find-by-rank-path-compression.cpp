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
#include "../../template/debug.cpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 0
#endif

/****************************************************************/

#define MAX 1005
vi p(MAX), r(MAX);

void makeSet(int n){
  for(int i  = 1 ; i <= n ; i++){
    p[i] = i;
    r[i] = 0;
  }
}

int find(int x){
  if(x == p[x]) return x;
  else return p[x] = find(p[x]);
}

void join(int x, int y){
  int px = find(x);
  int py = find(y);

  if(r[px] > r[py]){
    p[py] = px;
  }else{
    p[px] = py;
    if(r[px] == r[py]){
      r[py]++;
    } 
  }
}

int32_t main(){

  #ifdef _LOCAL_INPUT
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
  #endif
  
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  int n, t, q, x, y;
  cin >> n >> t >> q;
  makeSet(n);
  while(t--){
    cin >> x >> y;
    join(x, y);
  }
  
  while(q--){
    cin >> x >> y;
    if(find(x) == find(y)){
      cout << x << " and " << y << " are in the same set" << endl;
    }else{
      cout << x << " and " << y << " are in different set" << endl;
    }
  }

	return 0;
}