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
// returns true (+ intersection point) if two lines are intersect 
bool areIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2)) return false; // no intersection 
    // solve system of 2 linear algebraic equations with 2 unknowns
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    // special case: test for vertical line to avoid division by zero
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c); 
    else p.y = -(l2.a * p.x + l2.c); 
    return true; 
}

struct vec { 
    double x, y; // name: ‘vec’ is different from STL vector 
    vec(double _x, double _y) : x(_x), y(_y) {} 
};

// convert 2 points to vector a->b 
vec toVec(point a, point b) { return vec(b.x - a.x, b.y - a.y); 
}
// nonnegative s = [<1 .. 1 .. >1] // shorter.same.longer
vec scale(vec v, double s) { return vec(v.x * s, v.y * s); }

// translate p according to v
point translate(point p, vec v) {return point(p.x + v.x , p.y + v.y); }


 
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

        line l1,l2;

        point p1(4,4);
        point p2(1,1);
        pointsToLine(p1,p2,l1);

        point p3(2,0);
        point p4(0,2);
        pointsToLine(p3,p4,l2);

        debug(l1, l2);
        point px;
        debug(areIntersect(l1,l2,px));
        debug(px);
        
    }
	return 0;
}
