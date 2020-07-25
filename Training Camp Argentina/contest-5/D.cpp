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
#define MAX 300007

struct edge{
  int src;
  int dest;
  int weight;
  edge(){src = dest = weight = -1;}
  edge(int _src, int _dest, int _weight) : src(_src), dest(_dest), weight(_weight) {}

  bool operator < (edge ei) const{

    return ei.weight > weight;
  }

};

int main(){

  #ifdef _LOCAL_INPUT
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
  #endif
  
  ios_base::sync_with_stdio(false);
  cin.tie(0); cin.tie(0);
  int n,m,u,v,w,i,j;
  vector<edge> ady;
  vi dp(MAX);
  while(cin>>n>>m){
    vector<edge> ady;
    vi dp(MAX, 0);

    for(i =0 ; i < m ; i++){
      cin>>u>>v>>w;
      ady.push_back(edge(u,v,w));
    }

    sort(all(ady));

    int maxPath = 0, tempPath;
    stack<pair<int,int>> S;
    for(int i = m-1 ; i >= 0 ; i--){
      u = ady[i].src;
      v = ady[i].dest;
      w = ady[i].weight;

      tempPath = max(1, max(dp[u], dp[v] + 1));
      debug(tempPath);
      S.push(mp(u , tempPath));

      if(i == 0 || w != ady[i-1].weight){
          while(!S.empty()){
            pair<int,int> p0 = S.top(); S.pop();
            dp[p0.fi] = max(dp[p0.fi], p0.se);
            debug(maxPath, dp[p0.fi]);
            maxPath = max(maxPath, dp[p0.fi]);
          }
      }
    }
    cout << maxPath << endl;
  }

	return 0;
}
