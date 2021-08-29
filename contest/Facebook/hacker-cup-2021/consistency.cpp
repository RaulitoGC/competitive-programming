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
 
/******************* Template for Debugging **********/

/* Template from Tourist */
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "T" : "F");
}

template<typename A, typename B>
string to_string(unordered_map<A, B> umap){
  bool first = true;
  string res = "{";
  typename unordered_map<A, B>::iterator it;
  for (it = umap.begin(); it != umap.end(); it++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += "\n";
    res += "[" + to_string(it->first) + ":" + to_string(it->second) + "]";
  }
  res += "\n";
  res += "}";
  return res;
}

template<typename A, typename B>
string to_string(map<A, B> m){
  bool first = true;
  string res = "{";
  typename map<A, B>::iterator it;
  for (it = m.begin(); it != m.end(); it++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += "\n";
    res += "[" + to_string(it->first) + ":" + to_string(it->second) + "]";
  }
  res += "\n";
  res += "}";
  return res;
}

template<typename A>
string to_string(set<A> s){
  bool first = true;
  string res = "{";
  typename set<A>::iterator it;
  for (it = s.begin(); it != s.end(); it++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(*it);
  }
  res += "}";
  return res;
}

template<typename A>
string to_string(unordered_set<A> s){
  bool first = true;
  string res = "{";
  typename unordered_set<A>::iterator it;
  for (it = s.begin(); it != s.end(); it++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(*it);
  }
  res += "}";
  return res;
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

bool isVowel(char c){
  return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

bool isAlreadyConsistent(unordered_map<char, int> vowelCounts, unordered_map<char, int> consonantCounts){
  return (vowelCounts.size() == 1 && consonantCounts.size() == 0) || (vowelCounts.size() == 0 && consonantCounts.size() == 1);
}

bool isOnlyVowels(unordered_map<char, int> vowelCounts, unordered_map<char, int> consonantCounts){
  return vowelCounts.size() > 0 && consonantCounts.size() == 0;
}

bool hasOneVowel(unordered_map<char, int> vowelCounts){
  return vowelCounts.size() == 1;
}

bool hasOneConsonant(unordered_map<char, int> consonantCounts){
  return consonantCounts.size() == 1;
}

bool isOnlyConsonants(unordered_map<char, int> vowelCounts, unordered_map<char, int> consonantCounts){
  return consonantCounts.size() > 0 && vowelCounts.size() == 0;
}


int32_t main(){

  #ifdef _LOCAL_INPUT
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
  #endif
  
  ios_base::sync_with_stdio(false);
  cin.tie(0); cin.tie(0);

  int T, caseNumber = 1;
  string str;
  cin>>T;
  while(T--){
    cin>>str;
    unordered_map<char, int> vowelCounts;
    unordered_map<char, int> consonantCounts;
    int n = str.size();
    for(int i = 0 ; i < n ; i++){
      if(isVowel(str[i])){
        vowelCounts[str[i]]++;
      }else{
        consonantCounts[str[i]]++;
      }
    }

    debug(vowelCounts);
    debug(consonantCounts);
    cout << "Case #" << caseNumber << ": ";
    if(isAlreadyConsistent(vowelCounts, consonantCounts)){
      cout << "0"<< endl;
    }else if(hasOneVowel(vowelCounts) || isOnlyConsonants(vowelCounts, consonantCounts)){
      int result = 0;
      for(auto it = consonantCounts.begin() ; it != consonantCounts.end() ; it++){
        result += it->second;
      }
      cout << result << endl;
    }else if(hasOneConsonant(consonantCounts) || isOnlyVowels(vowelCounts, consonantCounts)){
      int result = 0;
      for(auto it = vowelCounts.begin() ; it != vowelCounts.end() ; it++){
        result += it->second;
      }
      cout << result << endl; 
    }else{
      
      int vowels = 0;
      int maxVowelItems = 0;
      for(auto it = vowelCounts.begin() ; it != vowelCounts.end() ; it++){
        if(maxVowelItems < it->second ){
          maxVowelItems = it->second;
        }
        vowels += it->second;
      }

      int consonants = 0;
      int maxConsonantItems = 0;
      for(auto it = consonantCounts.begin() ; it != consonantCounts.end() ; it++){
        if(maxConsonantItems < it->second ){
          maxConsonantItems = it->second;
        }
        consonants += it->second;
      }

      int maxSize = max(consonants, vowels);
      int minSize = min(consonants, vowels);
      debug(maxSize, minSize);
      int reduction;
      if(maxSize == vowels){
        reduction = maxConsonantItems;
      }else{
        reduction = maxVowelItems;
      }
      int result = maxSize + 2 * (minSize - reduction);
      cout << result << endl;
    }
    caseNumber++;
  }
	return 0;
}