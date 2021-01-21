#include <vector>
#include <algorithm>
using namespace std;

//Time : O(n)
// Space: O(1)
vector<int> findThreeLargestNumbers(vector<int> array) {
  vector<int> v;
	for(int i = 0; i < 3 ; i++){
		v.push_back(array[i]);
	}
	sort(v.begin(), v.end());
	int a = v[2], b = v[1], c = v[0];
	for(int i = 3 ; i < array.size() ; i++){
		if(array[i] >= a){
			int t = a;
			a = array[i];
			c = b;
			b = t;
		}else if(array[i] >= b){
			int t = b;
			b = array[i];
			c = t;
		}else if(array[i] >= c){
			c = array[i];
		}
	}
  return {c,b,a};
}

