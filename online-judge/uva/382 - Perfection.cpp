#include <bits/stdc++.h>
using namespace std;

#define test() cerr<<"Hello Family"<<"\n"
#define sz(array) (int)array.size() 
#define mset(array,value) memset(array,value,sizeof(array)) 

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

#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 0
#endif

/****************************************************************/

long c;


string getType(int n){
  debug("type");
  int sum = 0;
  if(n != 1) sum++;
  for(int i = 2 ; i <= sqrt(n); i++){
    if(n%i == 0) {
      if(i*i == n) sum += i;
      else sum += (i + n/i);
    }
  }
  
  debug(n, sum);
  if(sum == n) return "PERFECT";
  else if ( sum < n) return "DEFICIENT";
  else return "ABUNDANT";
}

int d(int n) { 
  return log10(n) + 1; 
}

int32_t main(){

  #ifdef DEBUG
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
  #endif
  
  ios_base::sync_with_stdio(false);
  cin.tie(0); cin.tie(0);

  vector<int> v;
  int n;
  while(cin>>n){
    if(n == 0) break;
    v.pb(n);
  }

  int sz = v.size();
  cout << "PERFECTION OUTPUT" << endl;
  string type = "";
  for(int i = 0 ; i< sz ; i++){
    type = getType(v[i]);  
    int dgts = d(v[i]);
    for(int j = 0 ; j < 5 - dgts; j++){
      cout<<' ';
    }
    debug(v[i], type);
    debug("---------------------");
    cout <<v[i]<<"  "<<type<<endl;
  }


  
  cout << "END OF OUTPUT" << endl;
	return 0;
}
