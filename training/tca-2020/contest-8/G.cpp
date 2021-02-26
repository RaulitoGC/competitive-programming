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

struct segment{
  int init;
  int fin;
  segment(int _init,int _fin) : init(_init), fin(_fin) {}
  segment() {init = fin = -1;}
  
  bool operator < (segment other) const{
      if(fin < other.fin) return true;
      else if(fin  == other.fin) return init < other.init;
      return false;
    }
};


unordered_set<int> res;
vector<segment> v;

int32_t main(){

  #ifdef _LOCAL_INPUT
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
  #endif
  
  ios_base::sync_with_stdio(false);
  cin.tie(0); cin.tie(0);

  int n,ii,ff,pi,pf;
  while(cin>>n){
    res.clear();
    v.clear();
    int i,j;
    for(i = 0 ; i < n ; i++){
      cin >> pi >> pf;
      ii = min(pi,pf);
      ff = max(pi,pf);
      v.pb(segment(ii,ff));
    }
    
    sort(all(v));
    
    segment t;
    
    
    stack<segment> S;
    for(int i = 0,j = 0 ; i < n ; ){
      t = v[i];
      
      j = i+1;
      res.insert(t.fin);
      while( j < n && v[j].init <= t.fin && t.fin <= v[j].fin ){
        j++;
      }
      debug(j);
      i = j;
    }

    int resS = sz(res);
    cout << resS << endl;
    unordered_set<int>::iterator it;
    for(it = res.begin() ; it != res.end() ; it++){
      cout << *it <<" ";
    }
    cout << endl;
    
  }
	return 0;
}
