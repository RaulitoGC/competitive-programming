#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
  return b == 0 ? a:gcd(b, a%b);
}

//Jungling algorithm
void translateArrayInPlace(vector<int> &array, int k){

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

/* *
 *  array = [1 2 3 4 5 6] , k = min (array.size(), k)
    1) rotate first k elements : array = [2 1 3 4 5 6]
    2) go to k to 0, and push the elements at the final of the array
       - k = 2 // idx = k-1
       - array.push_back(array[idx]) = [2 1 3 4 5 6 1]
       - array.push_back(array[idx]) = [2 1 3 4 5 6 1 2]
    3) remove the first k elements
      k = 2 -> array = [3 4 5 6 1 2]

    Time: O(k)
    Space: O(1)

    Edge cases:
     k > n // reverse all the array
     n = 5 , k = 8
     k = k % n  -> if k > n
     k <= 0 // return the same array
 * */

void removeFirstKElementsInPlace(vector<int>& array, int k){
  int idx = 0;
  while(idx < k){
    array.erase(array.begin());
    idx++;
  }
}  

void reverseFirstKelementsInPlace(vector<int>& array, int k){
  int start = 0;
  int end = k;
  int size = end / 2;
  for( int i = start ; i < size ; i++){
    int temp = array[i];
    array[i] = array[end - i - 1];
    array[end - i - 1] = temp;
  }
}

void translateKelementsInPlace(vector<int>& array, int k){
  if(k <= 0){
    return;
  }

  int n = array.size();

  if( k >= n){
    k = k % n;
  }

  reverseFirstKelementsInPlace(array, k);
  
  for(int i = k - 1 ; i >= 0 ; i--){
    array.push_back(array[i]);
  }

  removeFirstKElementsInPlace(array, k);
}

int main(){
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);
  v.push_back(6);

  int k = 9;
  translateKelementsInPlace(v, k);

  for(int i = 0 ; i < v.size() ; i++){
    cout << v[i] << " ";
  }

  cout << endl;
  return 0;
}
