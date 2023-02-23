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

#define MAX 100007

int res = 0;
int C[MAX]; 
vector<int> T[MAX];

void dfs(int  m, int s, int cc, int p) {
    if (cc > m) return ;
    if (C[s]) cc++;
    else cc=0;
 
    if (cc > m) return ;

    int ch = 0;
    int size = sz(T[s]), dest;
    for(int i=0; i < size ; i++) {
        dest = T[s][i];
        if (dest != p){
          dfs(m, dest, cc, s);
          ch++;
        }   
    }
    
    if (ch ==0 && cc <= m) {
      res++;
    }
}



int32_t main(){

  #ifdef _LOCAL_INPUT
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
  #endif
  
  ios_base::sync_with_stdio(false);
  cin.tie(0); cin.tie(0);

  int n,m,f,x,y;
  while(cin>>n>>m){
    
    for(int i = 1 ; i <= n ; ++i ){
        cin >>C[i];
    }

    for(int i = 1 ; i <= n - 1; ++i ){
        cin >> x >> y;
        T[x].push_back(y);
        T[y].push_back(x);
    }

    dfs(m, 1, 0, 0);
    cout << res << endl;
  }

	return 0;
}
