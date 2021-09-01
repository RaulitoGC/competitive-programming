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

// Time : O(nxm) : n : str1 size and m : str2 size
// Space: O(nxm) : n : str1 size and m : str2 size

const int MAX = 10;

int n, m;
vector<vector<int>> dp(MAX, vector<int>(MAX, 0));

int lcs(string str1, string str2){

  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= m ; j++){
      if(str1[i - 1] == str2[j - 1]){
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }else{
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }

  return dp[n][m];
}

void printLcs(string str1, string str2){
  int lcsValue = lcs(str1, str2);
  string res = "";
  int i = n, j = m;
  while(i > 0 && j > 0){
    if(dp[i][j] == dp[i-1][j-1] + 1 && str1[i-1] == str2[j-1]){
      if(dp[i][j] > 0){
        res = str1[i - 1] + res;
      }
      i--; j--;
    }else if(dp[i][j] == dp[i-1][j]){
      i--;
    }else{
      j--;
    }
  }

  cout << res << endl;
}

int32_t main(){

  #ifdef _LOCAL_INPUT
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
  #endif
  
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  string str1 = "a";
  string str2 = "acb";

  n = str1.size();
  m = str2.size();

  //cout << lcs(str1, str2) << endl;
  printLcs(str1, str2);

	return 0;
}
