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
#define vb vector<bool>
#define vvi vector<vector<int>>
#define mii map<int,int>
#define pii pair<int, int>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
 
/******************* Template for Debugging **********/

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

  int T,N,tc,i,j,l,r;
  char c;
  while(cin>>T){
    for(tc = 1 ; tc <= T ; tc++){
      cin>>N;
      vb O(N + 1); vb I(N + 1);

      for(i = 1 ; i <= N ; i++){
        cin>>c;
        I[i] = (c == 'Y');
      }

      for(i = 1 ; i <= N ; i++){
        cin>>c;
        O[i] = (c == 'Y');
      }

      vector<vector<char>> M(N + 1, vector<char>(N + 1));
      for(i = 1 ; i <= N ; i++){  
        l = i-1;
        r = i+1;

        M[i][i] = 'Y';
        if(l >= 1){
          M[i][l] = (O[i] && I[l])? 'Y' : 'N';
          for(j = l - 1; j >= 0 ; j--){
            if(M[i][j + 1] == 'Y' && I[j] && O[j+1]){
              M[i][j] = 'Y';
            }else{
              M[i][j] = 'N';
            }
          }
        } 
        if(r <= N){
          M[i][r] = (O[i] && I[r])? 'Y' : 'N';
          for(j = r + 1; j <= N ; j++){
            if(M[i][j - 1] == 'Y' && I[j] && O[j-1]){
              M[i][j] = 'Y';
            }else{
              M[i][j] = 'N';
            }
          }
        } 

        
      }
      cout << "Case #" << tc << ":"<< endl;
      for(i = 1 ; i <= N ; i++){
        for(j = 1 ; j <= N ; j++){
          cout << M[i][j];
        }
        cout << endl;
      }
    }
  }

	return 0;
}
