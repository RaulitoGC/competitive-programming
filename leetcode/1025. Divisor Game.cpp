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
    int size;
    vector<int> divs;
    void getDivisors(int n){
      divs.clear();
      size = (int) sqrt(n);
      divs.push_back(1);
      for(int i = 2; i <= size ; i++){
        if(n % i == 0){
          divs.push_back(i);
          if(n/i != i){
            divs.push_back(n/i);
          }
        } 
      }
    }

    bool divisorGame(int N) {
        vector<bool> dp(N + 5);
        int i,j;

        dp[1] = true; dp[2] = false; 
        // for(i = 3 ; i <= N ; i++){
        //   dp[i] = 1;
        // }

        for(i = 3 ; i <= N ; i++){
          getDivisors(i);
          dp[i] = !dp[i - divs[0]];
          
          if(dp[i] && divs.size() > 1){
            for(j = 1; j < divs.size() ; j++){
              dp[i] = (dp[i] && !dp[i - divs[j]]);
            }
          }
        }
        //debug(N, dp[N-1][1]);
        // debug(N, dp);
        // debug_out();
        return !dp[N];
    }
};

int32_t main(){

  #ifdef _LOCAL_INPUT
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
  #endif
  
  ios_base::sync_with_stdio(false);
  cin.tie(0); cin.tie(0);

  int n;
  bool res;
  Solution solution;
  while(cin>>n){
    res = solution.divisorGame(n);
    if(res) cout << "T"<< endl;
    else cout << "F" << endl;
    
  }

	return 0;
}
