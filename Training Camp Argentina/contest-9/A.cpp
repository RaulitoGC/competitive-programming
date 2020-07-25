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
#define exist(um, val) um.find(val)!=um.end()
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

string to_string(const char& c) {
  return to_string(c);
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

int32_t main(){

  #ifdef _LOCAL_INPUT
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
  #endif
  
  ios_base::sync_with_stdio(false);
  cin.tie(0); cin.tie(0);

  int n,m, i , j, k,r,c, h;
  char t;
  string ss;
  while(cin>>n>>m){

    vector<vector<char>> v(n,vector<char>(m));
    vector<string> dp(n);

    for(i = 0 ; i < n ; i++){
      cin >> ss;
      for(k = 0 ; k < m ; k++){
        v[i][k] = ss[k];
      }
      dp[i] = "#";
    }

    bool f = false;
    int res = 0;
    
    for(c = 0 ; c < m ; c++){

      t = v[0][c];
      k = 0;
      
      f = false;
      
      for(r = 1 ; r < n ; r++){
        if(v[r-1][c] > v[r][c]){
          if(dp[r] == "#" || dp[r-1] >= dp[r]){
            f = true;
            break;
          }
        }
      }
      
      if(f){
        res++;
      }else{  
          h = 0;
          while(h < n){
            dp[h] = dp[h] + v[h][c];
            h++;
          }
      }
    }
    
    cout << res << endl;
  }

	return 0;
}
