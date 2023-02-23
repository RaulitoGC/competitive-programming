#include <bits/stdc++.h>

using namespace std;

#define test() cout<<"Hello Family"<<"\n"
#define loop(n) for(int i = 0; i < n ; i++)
#define sz(array) (int)array.size() 
#define mset(array,value) memset(array,value,sizeof(array)) // [0] or [-1]

#define vi vector<int>
#define mii map<int,int>

typedef long long ll;

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
      
    long long arr[n + 1],temp1[n + 1], temp2[n + 1];
    for(int i = 1; i <= n ; i++){
      cin>>arr[i];
    }

    if(n == 1){
        cout <<"1 0"<<endl;
        continue;
    }

    if(n == 2){
        cout <<"1 1"<<endl;
        continue;
    } 

    temp1[1] = arr[1];
    for(int i = 2; i <= n ; i++){
      temp1[i] = (arr[i] + temp1[i - 1]);
    }

    temp2[n] = arr[n];
    for(int i = n - 1; i >= 0 ; i--){
      temp2[i] = (arr[i] + temp2[i + 1]);
    }

    long long index = 0, rMin = INT_MAX, temp;
    for(int i = 1; i <= n ; i++){
      temp = abs(temp1[i] - temp2[i]);
      if(temp < rMin){
        index = i;
        rMin = temp;
      }
    }

    if(temp1[index] == temp2[index]){
        cout << index <<" " << n - index << endl; 
    }else{
        if(temp1[index] < temp2[index]) cout <<index<<" "<< n - index<< endl;
        else cout << index - 1 <<" "<< n - index + 1 << endl; 
    } 

  }
	return 0;
}
