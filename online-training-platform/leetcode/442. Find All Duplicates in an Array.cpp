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

class Solution {
public:
    
    vector<int> countingSort(vector<int> arr,int n){
        int L = INT_MAX,R = INT_MIN;
        vector<int> res(n + 1, 0);
        for(int i = 0 ; i < n ; i++){
            if( arr[i] < L) L = arr[i];
            if( arr[i] > R) R = arr[i];
        }
    
        int k = R-L+1;
        int F[k];
    
        for(int i = 0 ; i < k ; i++) F[i] = 0;
    
        for(int i = 0 ; i < n ; i++) F[arr[i] - L]++;
    
        for(int i = 1 ; i < k ; i++) F[i] += F[i-1];
    
        for(int i = 0 ; i < n ; i++){
            res[F[arr[i] - L]] = arr[i]; 
            F[arr[i] - L]--;
        }
        
        return res;
    }
    
    vector<int> findDuplicates(vector<int>& nums) {
        int size = nums.size();
        vector<int> res;
        if(size == 0)  return res;
        nums = countingSort(nums, size);
        int t = nums[1];
        for(int i = 2 ; i <= size ; i++){
            if(t == nums[i]) res.push_back(nums[i]);
            t = nums[i];
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

  int n;
  vector<int> res;
  Solution solution;
  while(cin>>n){
    vector<int> in(n);
    for(int i = 0 ; i < n ; i++){
      cin>>in[i];
    }
    res = solution.findDuplicates(in);
    for(int i = 0 ; i < sz(res) ; i++){
      cout << res[i] << " ";
    }
  }

	return 0;
}
