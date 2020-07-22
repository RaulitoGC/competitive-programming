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


    void printMatrix(string name, int n, int matrix[][100]){
      cerr << name << endl;
      for(int i =0 ; i < n ; i++){
        for(int j =0 ; j < n ; j++){
          cerr << matrix[i][j] << " ";   
        }
        cerr << endl;
      }
    }

    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int matrix[N][N];
        int left[N][N];
        int right[N][N];
        int top[N][N];
        int bottom[N][N];
        int i,j;
        for(i = 0; i < N ; i++){
          for(j = 0; j < N ; j++){
            matrix[i][j] = 1;
          }
        }

        for(i = 0; i < mines.size() ; i++){
            matrix[mines[i][0]][mines[i][1]] = 0;
        }

        cerr << "matrix" << endl;
        for(int i =0 ; i < N ; i++){
          for(int j =0 ; j < N ; j++){
            cerr << matrix[i][j] << " ";   
         }
          cerr << endl;
        }

        
        for(i = 0; i < N ; i++){
          left[i][0] = matrix[i][0];
        }

        for(i = 0; i < N ; i++){
          for(j = 1; j < N ; j++){
            if(matrix[i][j] != 0){
              left[i][j] = left[i][j-1] + matrix[i][j];
              debug(matrix[i][j-1], matrix[i][j], left[i][j]);
            }else{
              left[i][j] = 0;
            } 
          }
        }

        for(i = 0; i < N ; i++){
          right[i][N-1] = matrix[i][N-1];
        }

        for(i = 0; i < N ; i++){
          for(j = N-2; j >= 0 ; j--){
            if(matrix[i][j] != 0) right[i][j] = right[i][j+1] + matrix[i][j];
            else right[i][j] = 0;
          }
        }


        for(j = 0; j < N ; j++){
          bottom[N-1][j] = matrix[N-1][j];
        }

        for(i = N-2; i >= 0 ; i--){
          for(j = 0; j < N ; j++){
            if(matrix[i][j] != 0) bottom[i][j] = bottom[i+1][j] + matrix[i][j];
            else bottom[i][j] = 0;
          }
        }

        for(j = 0; j < N ; j++){
          top[0][j] = matrix[0][j];
        }

        for(i = 1; i < N ; i++){
          for(j = 0; j < N ; j++){
            if(matrix[i][j] != 0) top[i][j] = top[i-1][j] + matrix[i][j];
            else top[i][j] = 0;
          }
        }

        cerr << "left" << endl;
        for(int i =0 ; i < N ; i++){
          for(int j =0 ; j < N ; j++){
            cerr << left[i][j] << " ";   
         }
          cerr << endl;
        }
        cerr << "right" << endl;
        for(int i =0 ; i < N ; i++){
          for(int j =0 ; j < N ; j++){
            cerr << right[i][j] << " ";   
         }
          cerr << endl;
        }

        cerr << "bottom" << endl;
        for(int i =0 ; i < N ; i++){
          for(int j =0 ; j < N ; j++){
            cerr << bottom[i][j] << " ";   
         }
          cerr << endl;
        }

        cerr << "top" << endl;
        for(int i =0 ; i < N ; i++){
          for(int j =0 ; j < N ; j++){
            cerr << top[i][j] << " ";   
         }
          cerr << endl;
        }

        // printMatrix("left", N, left);
        // printMatrix("right", N, right);
        // printMatrix("top", N, top);
        // printMatrix("bottom", N, bottom);

        int res = INT_MIN;
        for(i = 0; i < N ; i++){
          for(j = 0; j < N ; j++){
            res = max(res, min(min(left[i][j], right[i][j]), min(top[i][j], bottom[i][j])));
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

  int n, mines, size,x,y;
  int res;
  Solution solution;
  while(cin>>n>>mines){
    vvi v;
    for(int i = 0 ; i < mines ; i++){
      vi v0(2);
      cin>>v0[0]>>v0[1];
      v.pb(v0);
    }  
    res = solution.orderOfLargestPlusSign(n,v);
    cout << res;
    
  }

	return 0;
}
