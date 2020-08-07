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

/****************************************************************/

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    
    map<int, vector<pair<int,int>>> um;
    
    static bool comp(pair<int,int> p1, pair<int,int> p2){
        if(p1.second == p2.second) return p1.first < p2.first;
        return p1.second > p2.second;
    }
    
    void vt(TreeNode* root, int x, int y){
        
        if(root != NULL) um[x].push_back(make_pair(root->val,y));
        else return;
        
        vt(root->left, x - 1, y - 1);
        vt(root->right, x + 1, y - 1);
    }
    
    vector<int> r(vector<pair<int,int>> v){
        vector<int> res;
        sort(v.begin(), v.end(), comp);
        for(int i = 0; i < v.size() ; i++){
            res.push_back(v[i].first);
        }
        return res;
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vt(root, 0, 0);
        vector<vector<int>> res;
        vector<pair<int,int>> t;
        map<int, vector<pair<int,int>>>::iterator it;
        for(it = um.begin() ; it != um.end() ; it++){
            t = it->second;
            res.push_back(r(t));
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
