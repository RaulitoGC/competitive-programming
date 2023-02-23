#include <bits/stdc++.h>

using namespace std;

#define test() cout<<"Hello Family"<<"\n"
#define loop(n) for(int i = 0; i < n ; i++)
#define sz(array) (int)array.size() 
#define mset(array,value) memset(array,value,sizeof(array)) // [0] or [-1]

#define vi vector<int>
#define vvi vector<vector<int>>
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

int dp[2010][2010];
#define mod 1000000007
#define MAX 2010


int process(int n, int k, int index){
  if( k <= 0){
    return 1;
  }else if(dp[index][k] != -1){
    return dp[index][k];
  } 

  int res = 0;

  for(int i = index; i <= n ; i+=index){
    if(i%index == 0){
      res += (process(n, k - 1, i)%mod);
      res %= mod; 
    }
  }

  return dp[index][k] = res;
}

void init(){
   for(int i = 0; i < MAX ; i++){
     for(int j = 0; j < MAX ; j++){
       dp[i][j] = -1;
    }
   }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  
  int n,k;
  while(cin>>n>>k){
    init();
    cout << process(n,k,1) << endl;
  }
  
	return 0;
}
