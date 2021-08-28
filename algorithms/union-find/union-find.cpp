#include <bits/stdc++.h>

using namespace std;

#define MAX 1005

class UnionFind{

  vector<int> v;

  UnionFind(int n){
    for(int i = 0 ; i < n ; i++){
      v.push_back(i);
    }
  }

  int find(int x){
    if(x == v[x]){
      return x;
    }else{
      return find(v[x]);
    }
  }

  bool sameComponent(int x, int y){
    return find(x) == find(y);
  }

  void join(int x, int y){
    int xParent = find(x);
    int yParent = find(y);
    v[xParent] = y;
  }
};
