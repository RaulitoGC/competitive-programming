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

int n;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  while(cin>>n){

  int matrixF[n + 1][n + 1], matrixR[n + 1][n + 1], visited[n + 1][n + 1];
  int i, j;

  for(i = 1 ; i <= n ; i++ ){
    for(j = 1 ; j <= n ; j++ ){
      cin>>matrixF[i][j];
      visited[i][j] = false;
      matrixR[i][j]=matrixF[i][j];
    }
  }

  if(n == 1) {
    cout << matrixF[1][1] << endl;
    continue;
  }

  int res = -(matrixF[1][1] + matrixF[n][n]);
  //FUBICK
  
  for(i = 2 ; i <= n ; i++ ){
    matrixF[i][1] += matrixF[i-1][1];
  }

  for(j = 2 ; j <= n ; j++ ){
    matrixF[1][j] += matrixF[1][j-1];
  }

  for(i = 2 ; i <= n ; i++ ){
    for(j = 2 ; j <= n ; j++ ){      
      matrixF[i][j]+=max(matrixF[i - 1][j], matrixF[i][j - 1]);
    }
  }

  
  i = 1, j = 1;
  visited[i][j] = true;
  while(i != n || j != n){
    if(i == n){
      while(j <= n){
        visited[i][j] = true;
        j++;
      } 
      break;
    }
    if(j == n){
      while(i <= n){
        visited[i][j] = true;
        i++;
      }
      break;
    }
    if(matrixF[i + 1][j] > matrixF[i][j + 1]){
      visited[i + 1][j] = true;
      i++;
    }else{
      visited[i][j + 1] = true;
      j++;
    }
  }

  //debug(matrixF[n][n]);
  //RUBICK
  int init = matrixR[1][1], last = matrixR[n][n];
  //debug(init);
  for(int i = 1 ; i <= n ; i++ ){
    for(int j = 1 ; j <= n ; j++ ){
      if(visited[i][j]) matrixR[i][j] = 0;
    }
  }

  matrixR[1][1] = init;
  matrixR[n][n] = last;
  //debug(matrixR[1][1]);

  for(int i = n - 1 ; i >= 0 ; i--){
    matrixR[i][n] += matrixR[i+1][n];
  }

  for(int j = n - 1 ; j >= 0 ; j-- ){
    matrixR[n][j] += matrixR[n][j+1];
  }

  for(i = n - 1 ; i >= 0 ; i-- ){
    for(j = n - 1 ; j >= 0 ; j-- ){      
      matrixR[i][j]+=max(matrixR[i + 1][j], matrixR[i][j + 1]);
    }
  }

  // for(i = 1 ; i <= n ; i++ ){
  //   for(j = 1 ; j <= n ; j++ ){      
  //     cout << matrixR[i][j] << " ";
  //   }
  //   cout << endl;
  // }

//   debug(matrixR[1][1]);
//   debug(res);
  res += (matrixF[n][n] + matrixR[1][1]);
  cout << res << endl;
  }
	return 0;
}
