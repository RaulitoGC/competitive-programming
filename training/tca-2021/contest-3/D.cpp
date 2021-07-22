#include <bits/stdc++.h>
 
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
 
const int MAX_SIZE = 100000 + 3;
int n,ai;
 
long long maxLL(long long a, long long b){
  return (a > b) ? a : b;
}
 
int main(){
 
  #ifdef _LOCAL_INPUT
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
  #endif
 
	ios::sync_with_stdio(false);
  cin.tie(0);
  
  while(cin>>n){
    vector<int> c(MAX_SIZE, 0);
    vector<long long> dp(MAX_SIZE, 0);
    while(n--){
      cin>>ai;
      c[ai]++;
    }
    
    dp[1] = c[1];
    for(int i = 2; i < MAX_SIZE ; i++){
      long long prevProfit = (long long )c[i]*i;
      dp[i] = maxLL(dp[i-1], dp[i-2] + prevProfit);
    }
 
    cout << dp[MAX_SIZE - 1] << endl;
  }
 
	return 0;
}