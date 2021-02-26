#include <bits/stdc++.h>
using namespace std;

//Time complexity -> O(n)
//Space complexity -> O(1)

int getNthFib(int n) {
	if(n == 1) return 0;
	if(n == 2) return 1;
	
	int f0 = 0, f1 = 1, sum;
	
  for(int i = 3 ; i <= n ; i++){
		sum = f0 + f1;
		f0 = f1;
		f1 = sum;
	}
  return sum;
}

//Time complexity -> O(n)
//Space complexity -> O(n)
// int getNtgFibHelper(int n, int cache[]){
// 	if(n == 1) return cache[n - 1] = 0;
// 	if(n == 2) return cache[n - 1] = 1;
	
// 	return getNtgFibHelper(n - 1, cache) + getNtgFibHelper(n - 2, cache);
// }

// int getNthFib(int n) {
// 	int cache[n];
//   return getNtgFibHelper(n, cache);
// }

//Time complexity -> O(2ˆn)
//Space complexity -> O(n)
// int getNthFib(int n) {
//   if(n == 1) return 0;
// 	if(n == 2) return 1;
//   return getNthFib(n-1) + getNthFib(n-2);
// }

int32_t main(){
  int num;
  cin>>num;
  int res = getNthFib(num);
  cout << res << endl;

	return 0;
}
