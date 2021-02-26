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

ll maxLL(ll a, ll b){
  return (a > b)? a : b;
}

int32_t main(){

  #ifdef _LOCAL_INPUT
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
  #endif
  
  ios_base::sync_with_stdio(false);
  cin.tie(0); cin.tie(0);

  
  int T,N,tc,i,res;
  long long pi,hi,pl, pr, ep, ri, tmp;
  cin>>T;
  for(tc = 1 ; tc <= T ; tc++){
    cin>>N;
    unordered_map<ll, pair<ll, ll>> R;
    unordered_map<ll, pair<ll, ll>> EP;

    for(i = 0 ; i < N ; i++){
      cin>>pi>>hi;
      R[pi] = mp(pi-hi,pi+hi);
    }

    unordered_map<ll, pair<ll, ll>>:: iterator it;
    for(it = R.begin() ; it != R.end() ; it++){
      ri = it->fi;
      pl = it->se.fi;
      pr = it->se.se;
      debug(pl, pr);
      if(EP.find(pl) == EP.end()){
        EP[pl] = mp(0, abs(ri - pl));

        while(R.find(pl) != R.end()){
          tmp = R[pl].fi;

          if(EP.find(tmp) != EP.end()){
            EP[tmp].fi = EP[tmp].fi + abs(ri - pl);
          }

          if(R.find(tmp) != R.end()){
            pl = R[tmp].fi;
          }else{
            break;
          }
        }
      }else{
        tmp = EP[pl].se;
        EP[pl].se = max(tmp, abs(ri - pl));
      }

      if(EP.find(pr) == EP.end()){#include <bits/stdc++.h>
using namespace std;

#define test() cerr<<"Hello Family"<<"\n"
#define sz(array) (int)array.size() 
#define mset(array,value) memset(array,value,sizeof(array)) 

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

  
  int T,N,tc,i,a,b;
  string ss;
  cin>>T;
  for(tc = 1 ; tc <= T ; tc++){
    cin>>N;
    cin>>ss;
    a = 0; b = 0;
    for(i = 0 ; i < N ; i++){
      if(ss[i] == 'A') a++;
      else b++;
    }
    
    cout << "Case #" << tc << ":"<<endl;
    if(abs(a-b) == 1) cout << "Y" << endl;
    else cout << "N" << endl; 
  }
	return 0;
}


        EP[pr] = mp(abs(ri - pr), 0);

        while(R.find(pr) != R.end()){
          tmp = R[pr].se;

          if(EP.find(tmp) != EP.end()){
            EP[tmp].se = EP[tmp].se + abs(ri - pr);
          }

          if(R.find(tmp) != R.end()){
            pl = R[tmp].se;
          }else{
            break;
          }
        }

      }else{
        tmp = EP[pl].fi;
        EP[pl].fi = max(tmp, abs(ri - pr));
      }      
    }

    res = 0;
    for(it = EP.begin() ; it != EP.end() ; it++){
      pl = it->se.fi;
      pr = it->se.se;
      res = maxLL(res, pl + pr);
    }
    
    cout << "Case #" << tc << ": "<<res<<endl;
  }
	return 0;
}
