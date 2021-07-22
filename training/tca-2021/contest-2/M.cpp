#include <bits/stdc++.h>
 
using namespace std;
 
#define test() cout<<"Hello Family"<<"\n"
#define loop(n) for(int i = 0; i < n ; i++)
#define sz(array) (int)array.size() 
#define mset(array,value) memset(array,value,sizeof(array)) // [0] or [-1]
 
#define vi vector<int>
#define mii map<int,int>
 
typedef long long ll;
 
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
 
int n,m,k,t,a,b,i,j,nextItem;
 
const int WASTE = -1;
const int CARROT = 1;
const int KIWIS = 2;
const int GRAPES = 3;
 
typedef pair<int, int> pairs;
 
int main(){
 
  #ifdef _LOCAL_INPUT
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
  #endif
 
	ios::sync_with_stdio(false);
  cin.tie(0);
  
  while(cin>>n>>m>>k>>t){
    set<pairs> waste;
    while(k--){
      cin>>a>>b;
      waste.insert(make_pair(a,b));
    }
 
    while(t--){
      cin>>i>>j;
      if(waste.find(make_pair(i,j)) != waste.end()){
        cout << "Waste" << endl;
      } else{
        set<pairs>::iterator it;
        int wasted = 0;
        for(it = waste.begin() ; it != waste.end() ; it++){
          if((it->first <= i && it->second <= j) || (it->second >= j && it->first < i)){
            wasted++;
          }
        }
        debug(i, j);
        debug(wasted);
        int totalItems = m*(i - 1) + j;
        debug(totalItems);
        int realItems = totalItems - wasted;
        int item = realItems % 3;
        debug(item);
        debug();
        if(item == CARROT) cout << "Carrots" << endl;
        else if(item == KIWIS) cout << "Kiwis" << endl;
        else cout << "Grapes" << endl; 
      }
    }
 
  }
 
	return 0;
}