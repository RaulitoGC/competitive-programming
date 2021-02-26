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

#ifdef _DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 0
#endif

class Solution {
public:
    
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    
    int bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited){
        int sz = grid.size(), r,x, y;
        int res = 0;
        bool flag = false;
        vector<pair<int,int>> v;
        for(int i = 0 ; i < sz ; i++){
            r = grid[i].size();
            for(int j = 0 ; j < r ; j++){
                if(grid[i][j] == 2 && !visited[i][j]){
                    visited[i][j] = true;
                    for(int k = 0 ; k < 4 ; k++){
                        x = i + dx[k];
                        y = j + dy[k];
                        if( 0 <= x && x < sz && 0 <= y && y< r && grid[x][y] == 1){
                            v.push_back({x,y});
                        }
                    }
                }
            }
        }
        sz = v.size();
        for(int i = 0 ; i < sz ; i++){
            grid[v[i].first][v[i].second] = 2;
        }
        
        if(v.empty()) return 0;
        else return 1;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int sz = grid.size();
        vector<vector<bool>> visited(sz);
        int res = 0, r;
        for(int i = 0 ; i < sz ; i++){
            r = grid[i].size();
            visited[i] = vector<bool>(r,false);
        }
        
        for(int i = 0 ; i < sz ; i++){
            r = grid[i].size();
            for(int j = 0 ; j < r ; j++){
                res += bfs(grid, visited);
            }
        }
        
        for(int i = 0 ; i < sz ; i++){
            r = grid[i].size();
            for(int j = 0 ; j < r ; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        
        return res;
    }
};

int32_t main(){

  #ifdef _LOCAL_INPUT
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
  #endif
  
  ios_base::sync_with_stdio(false);
  cin.tie(0); cin.tie(0);


	return 0;
}
