#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
  return b == 0 ? a:gcd(b, a%b);
}

//Jungling algorithm
void rotateArrayInPlace(vector<int> &array, int k){

  int n = array.size(), size = gcd(n , k), j, d, temp;

  for(int i = 0 ; i < size ; i++){

    j = i;
    temp = array[i];
    while(true){
      d = (j+k)%n;
      if(d == i) break;
      array[j] = array[d];
      j = d;
    }
    array[j] = temp;
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
