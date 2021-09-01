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

int lcs(string str1, string str2){
  int n = str1.size();
  int m = str2.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  int result = 0;
  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= m ; j++){
      if(str1[i - 1] == str2[j - 1]){
        dp[i][j] = dp[i-1][j-1] + 1;
        result = max(result, dp[i][j]);
      }
    }
  }
  return result;
}

string lcs_and_substring(string str1, string str2){
  int n = str1.size();
  int m = str2.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  int result = 0;
  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= m ; j++){
      if(str1[i - 1] == str2[j - 1]){
        dp[i][j] = dp[i-1][j-1] + 1;
        result = max(result, dp[i][j]);
      }
    }
  }

  string substr = "";
  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= m ; j++){
      if(dp[i][j] == result){
        while(result--){
          substr = str1[i - 1] + substr;
          i--;
        }
        return substr;
      }
    }
  }
  return "";
}

// Time : O(nxm) : n : str1 size and m : str2 size
// Space: O(nxm) : n : str1 size and m : str2 size
int32_t main(){

  #ifdef _LOCAL_INPUT
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
  #endif
  
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  string str1 = "abcdfe";
  string str2 = "abcfed";

  cout << lcs(str1, str2) << endl;
  cout << lcs_and_substring(str1, str2) << endl;

	return 0;
}
