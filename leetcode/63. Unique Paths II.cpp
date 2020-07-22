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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      if(obstacleGrid.empty()) return 0;
      int r = obstacleGrid.size();
      int c = obstacleGrid[0].size();

      if(obstacleGrid[0][0] == 1) return 0;
      if(obstacleGrid[r-1][c-1] == 1) return 0;

      int top, left;

      vector<vector<long long>> dp(r, vector<long long>(c));

      dp[0][0] = 1;
      for(int j = 1; j < c ; ){
        if(obstacleGrid[0][j] == 1){
          while(j < c){
            dp[0][j] = -1;
            j++;
          }
        }else{
          dp[0][j] = 1;
          j++;
        }
      }

      for(int i = 1; i < r ; ){
        if(obstacleGrid[i][0] == 1){
          while(i < r){
            dp[i][0] = -1;
            i++;
          }
        }else{
          dp[i][0] = 1;
          i++;
        }
      }
      //debug(obstacleGrid);
      // debug(dp);
      // debug_out();
      

      for(int i = 1; i < r ; i++){
        for(int j = 1; j < c ;j++){
          if(obstacleGrid[i][j] == 1) dp[i][j] = -1;
          else dp[i][j] = 1;
        }
      }
      // debug(dp);
      // debug_out();
      for(int i = 1; i < r ; i++){
        for(int j = 1; j < c ;j++){
          if(dp[i][j] != -1){
            top = (dp[i -1][j] != -1)? dp[i -1][j] : 0;
            left = (dp[i][j - 1] != -1)? dp[i][j - 1] : 0;
            dp[i][j] = top + left;
          } 
        }
      }
      
      return dp[r-1][c-1];
    }
};

int32_t main(){

  #ifdef _LOCAL_INPUT
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
  #endif
  
  ios_base::sync_with_stdio(false);
  cin.tie(0); cin.tie(0);

  int m,n, res;
  Solution solution;
  while(cin>>m>>n){
    vector<vector<int>> v(m,vector<int>(n));
    for(int i = 0; i < m ; i++){
        for(int j = 0; j < n ;j++){
          cin >>v[i][j];
        }
      }

    res = solution.uniquePathsWithObstacles(v);
    cout << res << endl;  
  }

	return 0;
}
