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

int main(){
	ios::sync_with_stdio(false);
  cin.tie(0);
  int R,C,A,B,ai,bi,i,j,t1,t2;
  char block, step;
  while(cin>>R>>C>>A>>B){
    int rows[A];
    int cols[B];
    for(i = 0 ; i < A ; i++){
      cin>>rows[i];
    }

    for(i = 0 ; i < B ; i++){
      cin>>cols[i];
    }

    block = 'B';
    for( i = 0; i < A ; i++){
      t1 = rows[i];
      while(t1--){
        step = block;
        for(j = 0 ; j < B ; j++){
          t2 = cols[j];
            while(t2--){
              cout <<step;
            }
            if(step == 'B')step = 'W';
            else step = 'B';
        }
        cout << endl;
      }
      if(block =='B') block = 'W';
      else block = 'B';
    }
    
  }
	
	return 0;
}
