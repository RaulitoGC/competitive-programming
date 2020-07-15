/***************************************************************
Template code for Competitive programming
Author: Raul Guzman
****************************************************************/
#include <bits/stdc++.h>
 
using namespace std;
 
//#define DEBUG true // Comment this line after send the code 
 
#define test() cout<<"Hello Family"<<"\n"
#define loop(n) for(int i = 0; i < n ; i++)
#define sz(array) (int)array.size() 
#define mset(array,value) memset(array,value,sizeof(array)) // [0] or [-1]
 
#define vi vector<int>
#define vvi vector<vector<int>>
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
 
const int TYPE_1 = 1;
const int TYPE_2 = 2;
 
int main(){
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);
  
  int m,n;
  while(cin>>n>>m){
    long long A[n];
    long long B[n];
    int i,type,pos,x,y,k, start = -1, end = -1;
    for(i = 0;  i < n ; i++)  cin>> A[i];
    for(i = 0;  i < n ; i++)  cin>> B[i];
 
    while(m--){
      cin>>type;
      if(type == TYPE_1){
        cin>>x>>y>>k;
        for(i = 0;  i < k ; i++){
          B[y+i-1] = A[x+i-1];
        }
      }else {
        cin>>pos;
        cout << B[pos-1]<<endl;
      } 
    }
  }
	return 0;
}