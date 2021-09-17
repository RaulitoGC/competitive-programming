#include <bits/stdc++.h>
using namespace std;
#define test() cerr<<"Hello Family"<<"\n"
#define sz(array) (int)array.size() 
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

#ifdef _DEBUG
#include "../../template/debug.cpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 0
#endif

/****************************************************************/

// Time : O(nxm) : n : str1 size and m : str2 size
// Space: O(nxm) : n : str1 size and m : str2 size

const int MAX = 10;

int n;
int counts = 0;
void lis(vector<int> arr){
  int n = arr.size();
  vector<int> T(n,1);
  int j = 0, i = 1;
  while( i < n){
    j = 0;
    while(j < i){
      if(arr[j] < arr[i]){
        T[i] = max(T[j] + 1, T[i]);
        if(T[i] >= 3) counts++;
      }
      j++;
    }
    i++;
  }
  debug(T);
  debug(counts);
}

int32_t main(){

  #ifdef _LOCAL_INPUT
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
  #endif
  
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  vector<int> arr = {1,2,3,4};
  lis(arr);
	return 0;
}
