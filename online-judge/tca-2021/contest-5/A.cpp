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
#include "debug.cpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 0
#endif

/****************************************************************/

long long n,ai;

vector<string> split(const string& s){
  vector<string> tokens;
  string token;
  istringstream tokenStream(s);
  while (getline(tokenStream, token, '+')){
      debug(token);
      tokens.push_back(token);
  }
  return tokens;
}

string ss;

int32_t main(){

  #ifdef _LOCAL_INPUT
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
  #endif
  
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  while(cin>>ss){
    vector<string> numbers = split(ss);
    int n = 0;
    vector<int> v;
    for(int i = 0 ; i < numbers.size() ; i++){
      string num = numbers[i];
      v.pb(stoi(num));
    }

    sort(all(v));
    string res = "";
    int size = sz(v);
    for(int i = 0 ; i < size ; i++){
      debug(v[i]);
      debug(to_string(v[i]));
      res += to_string(v[i]);
      if( i != size - 1){
        res += "+";
      }
    }
    debug(res);
    cout << res << endl;
  }


	return 0;
}
