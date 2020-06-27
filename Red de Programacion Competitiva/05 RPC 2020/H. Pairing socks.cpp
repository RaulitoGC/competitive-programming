/***************************************************************
Template code for Competitive programming
Author: Raul Guzman
****************************************************************/
#include <bits/stdc++.h>

using namespace std;

#define test() cout<<"Hello Family"<<"\n"
#define loop(n) for(int i = 0; i < n ; i++)
#define sz(array) (int)array.size() 
#define mset(array,value) memset(array,value,sizeof(array)) // [0] or [-1]

#define vi vector<int>
#define mii map<int,int>

typedef long long ll;
 
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

#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 0
#endif

/****************************************************************/

ll n,ai,t1,t2;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

  while(cin>>n){
    stack<ll> s,aux;
    for(int i = 0; i < 2*n ; i++){
      cin>>ai;
      aux.push(ai);
    }
    
    while(!aux.empty()){
        s.push(aux.top());
        aux.pop();
    }
    
    ll steps = 0, paired = 0;
    t1 = 0;
    t2 = 0;
    while(!s.empty()){
        t2 = 0;
      t1 = s.top();
      if(!aux.empty()){
        t2 = aux.top();
      }
    
      if(t1 == t2){
        if(!s.empty()) s.pop();
        if(!aux.empty()) aux.pop();
        paired++;
        steps++;      
      }else{
        if(!s.empty()) s.pop();
        aux.push(t1);
        steps++;
      }
    }
    
    if(n == paired) cout <<steps<<endl;
    else cout<<"impossible"<<endl;
  }
	
	return 0;
}
