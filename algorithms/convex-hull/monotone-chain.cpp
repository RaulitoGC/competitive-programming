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

struct Point{
  int x,y;

  bool operator < (const Point& p) const{
    return x < p.x || ( x == p.x && y < p.y );
  }

  bool operator == (const Point& p) const{
    return x == p.x && y == p.y;
  }
};

int cross(Point O, Point A, Point B){
  return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
  
string getKey(int x, int y){
  return to_string(x) + "," + to_string(y);
}

vector<Point> convexHull(vector<Point>& points){
  vector<Point> hull;

  sort(points.begin(), points.end());
  int n = points.size();

  for(int i = 0 ; i < n ; i++){
    int sz = hull.size();
    while( sz >=  2 && cross(hull[sz - 2], hull[sz - 1], points[i]) < 0){
      hull.pop_back();
      sz = hull.size(); 
    }
    hull.push_back(points[i]);
  }
  
  for(int i = n - 1, t = hull.size(); i >= 0 ; i--){
    int sz = hull.size();
    while( sz >= t && cross(hull[sz - 2], hull[sz - 1], points[i]) < 0){
      hull.pop_back();
      sz = hull.size();
    }
    hull.push_back(points[i]);
  }

  unordered_set<string> us;
  vector<Point> res;
  for(auto it = hull.begin() ; it != hull.end() ; it++){
    string key = getKey((*it).x, (*it).y);
    if(us.find(key) == us.end()){
      res.push_back(*it);
    }
    us.insert(key);
  }

  return res;
}

int32_t main(){

  #ifdef _LOCAL_INPUT
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
  #endif
  
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  test();
  vector<Point> points;
  points.push_back({1,1});
  points.push_back({2,2});
  points.push_back({2,0});
  points.push_back({2,4});
  points.push_back({3,3});
  points.push_back({4,2});

  vector<Point> ch = convexHull(points);
  for(int i = 0 ; i < ch.size() ; i++){
    cout << "[" << ch[i].x << "," << ch[i].y << "] " << endl;
  }

  cout << endl;

	return 0;
}