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
  int rob(vector<int>& nums) {
      int n = nums.size();
      if(n == 0) return 0;
      if(n == 1) return nums[0];

      int dp[n + 5];
      dp[1] = nums[0];
      dp[2] = max(dp[1], nums[1]);
      for( int i = 3 ; i <= n ; i++){
        dp[i] = max(nums[i-1] + dp[i-2], dp[i-1]);
      }    
      return dp[n];
  }
};

int32_t main(){

  #ifdef _LOCAL_INPUT
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
  #endif
  
  ios_base::sync_with_stdio(false);
  cin.tie(0); cin.tie(0);

  int n,res;
  Solution solution;
  while(cin>>n){
    vi v(n);
    for(int i = 0 ; i < n ; i++){
      cin >> v[i];
    }
    res = solution.rob(v);
    cout << res << endl;  
  }

	return 0;
}
