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

const int MAX = 10;
int p = 3;

int charToInt(char c){
  return (int)c - 96;
}

int getHash(string str, int start, int end){
  int exp = 0;
  int hash = 0;
  for(int i = start; i < end; i++){
    hash += charToInt(str[i])* pow(p, exp);
    exp++;
  }
  return hash;
}

void rabin_karp(string str, string pattern){
  int n = str.size();

  int m = pattern.size();
  int h = getHash(pattern, 0 , m);
  vector<int> matches;
  debug(h);

  int lastHash = getHash(str, 0, m);
  debug(lastHash);
  if(lastHash == h) matches.push_back(0);
  for(int i = 1 ; i <= n - m ; i++){
    
    lastHash -= charToInt(str[i - 1]);
    lastHash /= p;
    lastHash += charToInt(str[m + i - 1]) * pow(p, m - 1);
    debug(lastHash);
    if(lastHash == h){
      matches.push_back(i);
    }
  }

  if(matches.empty()) cout << "-1" << endl;
  else cout << matches.size() << endl;
}

int32_t main(){

  #ifdef _LOCAL_INPUT
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
  #endif
  
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  string str = "axxbc";
  string pattern = "abc";

  rabin_karp(str, pattern);
	return 0;
}
