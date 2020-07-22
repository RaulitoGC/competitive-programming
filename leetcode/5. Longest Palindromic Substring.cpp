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
    
    bool proccess(int i, int j,string& s){
      if(i == j) return true;
      if(i == j+1) return s[i] == s[j];
      return s[i] == s[j] && proccess(i+1, j-1,s);
    }
    
    string longestPalindrome(string s) {
        int size = s.size(), length;

        vector<vector<bool>> dp(size , vector<bool>(size,false));

        int besti = 0, bestj = 0,bestl = 0,l;

        for(int i = 0; i < size ; i++){
          for(int j = size - 1; j >= i ; ){
            //debug(i,j);
            if(proccess(i,j,s)){
              l = j - i + 1;
              if(bestl < l){
                bestl = l;
                besti = i;
                bestj = j;
              }
              j -=l;
            }else{
              j--;
            }
          }
        }
        return s.substr(besti, bestj - besti + 1);      
    }
};


int32_t main(){

  #ifdef _LOCAL_INPUT
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
  #endif
  
  ios_base::sync_with_stdio(false);
  cin.tie(0); cin.tie(0);

  string s,res;
  Solution solution;
  while(cin>>s){
    res = solution.longestPalindrome(s);
    cout << res << endl;  
  }

	return 0;
}
