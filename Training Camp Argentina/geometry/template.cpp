/***************************************************************
Template code for Competitive programming
Author: Raul Guzman
****************************************************************/
#include <bits/stdc++.h>

using namespace std;

#define DEBUG true // Comment this line after send the code 

#define test() cout<<"Hello Family"<<"\n"
#define loop(n) for(int i = 0; i < n ; i++)
#define sz(array) (int)array.size() 
#define mset(array,value) memset(array,value,sizeof(array)) // [0] or [-1]

#define vi vector<int>
#define mii map<int,int>

typedef long long ll;

/******************* Geometry template **********/

#define EPS 1e-9
#define PI acos(-1.0)
#define DEG_TO_RAD (PI/180.0)
#define RAD_TO_DEG (180.0/PI)

struct point{
    double x,y;
    point(){x = y = 0.0;}
    point(double _x, double _y) : x(_x), y(_y) {}
    bool operator < (point pi) const{
        if(fabs(x - pi.x) > EPS) return x < pi.x;
        return y < pi.y;
    }

    bool operator == (point pi) const{
        return ((fabs(x - pi.x) < EPS) && (fabs(y - pi.y) <  EPS));
    }

    double dist(point pi){
        return hypot(x - pi.x, y - pi.y);
    }

    inline double degToRad(double theta){
        return theta*DEG_TO_RAD;
    }

    inline double radToDeg(double rad){
        return rad*RAD_TO_DEG;
    }

    point rotate(double theta) {
        double rad = degToRad(theta); 
        return point(x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad)); 
    }
};

struct line{
    double a, b, c; // ax + by + c = 0
    line(){a = b = c = 0.0;}
    line(int _a, int _b, int _c): a(_a), b(_b), c(_c) {}
};

void pointsToLine(point p1, point p2, line &l){
    if (fabs(p1.x - p2.x) < EPS) { // vertical line 
        l.a = 1.0; l.b = 0.0; l.c = -p1.x; 
    }else {// default values
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0; // IMPORTANT: we fix the value of b to 1.0 
        l.c = -(double)(l.a * p1.x) - p1.y;   
    }
}

bool areParallel(line l1, line l2) { // check coefficients a & b 
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS); 
}
bool areSame(line l1, line l2) { // also check coefficient c 
    return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS); 
}

 
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

string to_string(point p){
    string res = "{";
    res += to_string(p.x);
    res += " ,";
    res += to_string(p.y);
    res += "}";
    return res;
}

string to_string(line l){
    string res = "{";
    res += to_string(l.a);
    res += "x + ";
    res += to_string(l.b);
    res += "y + ";
    res += to_string(l.c);
    res += " = 0";
    res += " }";
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


int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);

    point p;
    while(cin>>p.x>>p.y){
        point p1(4,4);
        cout << p.dist(p1) << endl;
        point aux = p.rotate(90.0);
        debug(aux);
        point aux2 = p.rotate(-90.0);
        debug(aux2);
        line l;
        pointsToLine(p1,p,l);
        debug(l);
        line l1(3,4,9);
        line l2(3,4,9);
        line l3(3,4,5);
        debug(areParallel(l1,l3));
        debug(areSame(l1,l3));
    }
	return 0;
}
