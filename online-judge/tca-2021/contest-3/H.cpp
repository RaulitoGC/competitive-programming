#include <bits/stdc++.h>
#include <unordered_map>
 
using namespace std;
 
#define test() cout<<"Hello Family"<<"\n"
#define loop(n) for(int i = 0; i < n ; i++)
#define sz(array) (int)array.size() 
#define mset(array,value) memset(array,value,sizeof(array)) // [0] or [-1]
 
#define vi vector<int>
#define mii map<int,int>
 
typedef long long ll;
 
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
 
#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 0
#endif
 
/****************************************************************/
 
const int MOD = 10007;
int n,ai;
 
bool cmp1(const int &a, const int &b){
  return a < b;
}
 
bool cmp2(const int &a, const int &b){
  return a > b;
}
 
int32_t main(){
 
  #ifdef _LOCAL_INPUT
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
  #endif
 
	ios::sync_with_stdio(false);
  cin.tie(0);  
 
  // int a = 100000;
  // int b = a % MOD;
 
  // long long c = (long long)a*a;
  // debug(c);
  // int d = c % MOD;
  // int x = (a % MOD * a % MOD) % MOD;
  // debug(x,d);
  
  while(cin>>n){
    vector<int> T;
    vector<int> L;
    int size = n;
    
    while(n--){
      cin>>ai;
      T.push_back(ai);
      L.push_back(ai);
    }
 
    sort(T.begin(), T.end(), cmp1);
    sort(L.begin(), L.end(), cmp2);
 
    long long res = 0;
    debug(T);
    debug(L);
    for(int i = 0 ; i < size ; i++){
      res += ((T[i] % MOD) * (L[i] % MOD)) % MOD;
      debug(res);
    }
    res = res % MOD;
    cout << res << endl;
  }
 
	return 0;
}