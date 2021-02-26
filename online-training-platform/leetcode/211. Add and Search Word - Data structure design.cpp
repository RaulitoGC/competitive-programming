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

class WordDictionary {
public:
    
    const static int N = 28;

    struct node {
      bool word;
      node *v[N];    
    };
  
    int charToIndex(char c) {
      return (int) (c - 'a');
    }
  
    node *new_node() {
      node *x = (node *)malloc(sizeof(node));
      if (x) {
        x->word = false;
        for (int i = 0; i < N; ++i) x->v[i] = NULL;
      }
      return x;
    }
  
    void insert(string s) {
      node *x = trie;
      int size = s.size();
      for (int i = 0; i < size; ++i) {
        int k = charToIndex(s[i]);
        if (!x->v[k]) {
          x->v[k] = new_node();
        }
        x = x->v[k];
      }
      x->word = true;
    }
  
    bool find(string s, node* x, int index) {
      if(index == s.size()){
        return x->word;
      }
      
      char c = s[index];
      if(c == '.'){
        for(int i = 0; i < N ; i++){
          if(x->v[i] != NULL && find(s, x->v[i], index + 1)) return true;
        }
        return false;
      }else{
        return x->v[charToIndex(c)] != NULL && find(s, x->v[charToIndex(c)] ,index + 1);
      }
    }

    node *trie;
    WordDictionary() {
      trie = new_node();
    }
    
    void addWord(string word) {
      insert(word);
    }
    
    bool search(string word) {
      return find(word, trie, 0);
    }
};

int32_t main(){

  #ifdef _LOCAL_INPUT
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
  #endif
  
  ios_base::sync_with_stdio(false);
  cin.tie(0); cin.tie(0);

  
  WordDictionary *solution = new WordDictionary();
  int m,n;
  string word;
  while(cin>>m>>n){
    for(int i = 0 ; i < m ; i++){
      cin >> word;
      solution->addWord(word);
    }
    for(int i = 0 ; i < n ; i++){
      cin >> word;
      int res = solution->search(word);
      cout << res << endl;
    }
  }

	return 0;
}
