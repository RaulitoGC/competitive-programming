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
 
/******************* Tourist's Template for Debugging **********/

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

class Solution {
public:
    
    
    // bool isValid(char)
    
    int numDecodings(string s) {
        unordered_set<string> um;
        string ss = "";
        for(int i = 0. ; i < 27 ; i++){
            ss = to_string(i);
            um.insert(ss);
        }
        int size = s.size();
        int dp[size + 3];
        if(size <= 2) return size;
        
        dp[0] = 0;
        if(um.find(s.substr(0,2)) != um.end()){
          dp[1] = 2;
        }else{
          dp[1] = 1;
        }

        int res = 0;
        for(int i = 2 ; i < size ; i++){
          debug(s.substr(i-1, 2));
          if(um.find(s.substr(i-1, 2)) != um.end()){
            dp[i] = 2*(dp[i - 1] - 1) + 1;
          }else{
            dp[i] = dp[i-1];
          }
        }
        
        return dp[size - 1];
    }
};

int32_t main(){

  #ifdef _LOCAL_INPUT
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
  #endif
  
  ios_base::sync_with_stdio(false);
  cin.tie(0); cin.tie(0);

  string ss;
  int res;
  Solution solution;
  while(cin>>ss){
    res = solution.numDecodings(ss);
    cout << res << endl;  
  }

	return 0;
}
