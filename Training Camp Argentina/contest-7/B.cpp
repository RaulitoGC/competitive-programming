#include <bits/stdc++.h>
using namespace std;

#define test() cerr<<"Hello Family"<<"\n"
#define sz(array) (int)array.size() 
#define mset(array,value) memset(array,value,sizeof(array)) // [0] or [-1]

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

string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "T" : "F");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
  
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for(const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "<" + to_string(p.first) + ", " + to_string(p.second) + ">";
}

void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef _DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 0
#endif

/****************************************************************/

ll maxLL(ll a, ll b){
  //debug(a,b);
  return (a < b)? b: a;
}

int32_t main(){

  #ifdef _LOCAL_INPUT
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
  #endif
  
  ios_base::sync_with_stdio(false);
  cin.tie(0); cin.tie(0);

  ll n;
  while(cin>>n){
    vector<ll> v(n + 2), left(n + 2, 0), right(n + 2, 0);
    int i,j;
    for(i = 1 ; i <= n ; i++){
      cin>>v[i];
    }

    if( n == 1){
      cout << "1" << endl;
      continue;
    }

    if( n == 2){
      cout << "2" << endl;
      continue;
    }

    left[1] = 1;

    for(int i = 2 ; i <= n ; i++){
      left[i] = 1;
      if(v[i - 1] < v[i]) left[i] = left[i - 1] + 1;
    }

    right[n] = 1;
    for(int i = n - 1 ; i >= 1 ; i--){
      right[i] = 1;
      if(v[i] < v[i + 1]) right[i] = right[i + 1] + 1;
    }

    
    ll res = INT_MIN, l;
    v[0] = 0; v[n+1] = INT_MAX;
    for(int i = 1; i <= n; i++){
      
      if(v[i + 1]  - v[i - 1] >= 2){
        l = left[i - 1] + right[i + 1] + 1;
      }else{
        l = (maxLL(left[i - 1], right[ i + 1] ) + 1);
      } 
      
      res = maxLL(res, l);
      
    }
    
    cout << res << endl;

  }
	return 0;
}
