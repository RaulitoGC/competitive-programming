#include <bits/stdc++.h>

using namespace std;

//Jungling algorithm
void rotateArrayInPlace(vector<int> &array, int k){
  int n = array.size();
  for( int i = 0 ; i < n/2 ; i++){
    swap(array[i], array[n - i - 1]);
  }
}

int main(){
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);
  v.push_back(6);

  int k = 2;
  rotateArrayInPlace(v, k);

  for(int i = 0 ; i < v.size() ; i++){
    cout << v[i] << " ";
  }

  cout << endl;
  return 0;
}
