#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout<<#x<<" : "<<x<<"\n"
#define debug2(x, y) cout << #x << " : " << x << " - " << #y << " : " << y << "\n"
#define debug3(i,n,array) for(int i = 0; i < n ; i++) cout<<#array[i]<<" : "<<array[i]<<"\n"
#define test() cout<<"Hello world"<<"\n"

#define loop(i,n) for(int i = 0; i < n ; i++)
#define read(n) cin >> n
#define readSS(ss1,ss2) cin >> ss1 >> ss2
#define write(n) cout << n << "\n"

#define sz(array) (int)array.size()
#define mset(array,value) memset(array,value,sizeof(array))
#define vi vector<int>
#define vf vector<float>
#define vll vector<ll>
#define msi map<int,string>
#define mss map<string,string> 

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;


bool p2(int x, int target){
	return x <= target;
}

int bs_upper_bound(vector<int> S, int target){
	// First item of the set S
	int low = 0;
	// Last item of the set S
	int high = S.size() - 1;

	// We use < since the search space can be [a,b] and we are looking for a upper_value
	while(low < high){
		// In order to rounding down make median = l + (h - l)/2
		int median = low + (high - low)/2;
		cout << low << " -- "<< high << endl;
		// In this case the predicate is "Is S[median] equals or less than target?"
		// Since we are sure that all the values to the right are greather thant target
		// We can move to the left side in order to verify if there is at least one more value
		// thant can satisfy the predicate p1
		if(p2(S[median], target)){
			low = median + 1;
		// Since we are sure that predicate p(x) is false, we can decide what is 
		// our new search space. For this case if target is less than the S[median]
		// it means that our new search space is:
		// S[median] = 3
		// [1,1,1,1,3,3,3,3] -> Search space [0, 7]
		// [1,1,1,1,-,-,-,-] -> Search space [0, 4]
		}else {
			high = median;
		}
		cout << low << " -|- "<< high << endl;
		cout << endl;

		// Complain :  p(x) is false for all x in S!
		if(!p2(S[low], target)){
			return low;
		}
	}

	// When we are out of search space, we can return low since, we are looking for the lower_bound position
	return low;
} 


bool p1(int x, int target){
	return x >= target;
}

// Lower_Bound: return the position of the value equals or less than target
int bs_lower_bound(vector<int> S, int target){
	// First item of the set S
	int low = 0;
	// Last item of the set S
	int high = S.size() - 1;

	// We use < since the search space can be [a,b] and we are looking for a lower_value
	while(low < high){
		// In order to rounding down make median = l + (h - l + 1)/2
		// the '+1' is to avoid infinite loop
		int median = low + (high - low)/2;

		// In this case the predicate is "Is S[median] equals or less than target?"
		// Since we are sure that all the values to the right are greather thant target
		// We can move to the left side in order to verify if there is at least one more value
		// thant can satisfy the predicate p1
		if(p1(S[median], target)){
			high = median;
		// Since we are sure that predicate p(x) is false, we can decide what is 
		// our new search space. For this case if target is less than the S[median]
		// it means that our new search space is:
		// S[median] = 2
		// [1,2,2,2,2,2,2,2,2,2,2,2] -> Search space [0, 12]
		// [-,-,-,-,-,-,2,2,2,2,2,2] -> Search space [0, 5]
		}else {
			low = median + 1;
		}
		
		// Complain :  p(x) is false for all x in S!
		// if(p1(S[low], target)){
		// 	return low;
		// }
	}

	// When we are out of search space, we can return low since, we are looking for the lower_bound position
	return low;
}

bool p(int a, int b){
	return a == b;
}

// Classic : Search for value in set S, return the position if it exist, otherwise return -1
int bs(vector<int> S, int target){
	// First item of the set S
	int low = 0;
	// Last item of the set S
	int high = S.size() - 1;

	// We use <= since the search space can be [a,b] and we are looking for a
	while(low < high){
		// In order to rounding down make median = l + (h - l)/2
		int median = low + (high - low)/2;

		// In this case the predicate is "Is S[median] equals to target?"
		if(p(S[median], target)){
			return median;
		// Since we are sure that predicate p(x) is false, we can decide what is 
		// our new search space. For this case if target is less than the S[median]
		// it means that our new search space is:
		// [x,x,x,x,x,x,S[median],x,x,x,x,x,x] -> Search space [0, 12]
		// [x,x,x,x,x,x,-,-,-,-,-,-,-] -> Search space [0, 5]
		}else if(target < S[median]){
			high = median - 1;
		}else{
			low = median + 1;
		}
	}
	// When we are out of search space, we can return any invalid value,
	// for this case [-1]
	return -1;
}

int main(){

	vector<int> v;

	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(3);
	v.push_back(3);
	v.push_back(3);
	v.push_back(3);

	//v.push_back(3);
	// v.push_back(4);
	// v.push_back(4);
	// v.push_back(4);
	// v.push_back(4);

	int num;
	while(cin >> num){
		//int idx = bs(v, num);
		auto lower_it = lower_bound(v.begin(), v.end(), num);
		//auto upper_it = upper_bound(v.begin(), v.end(), num);
		auto it = bs_lower_bound(v, num);
		//auto it = bs_upper_bound(v, num);
		cout << "custom upper bound " << it << endl;
		cout <<"lower bound = " << lower_it  - v.begin()<< endl;
		//cout <<"upper bound = " << upper_it  - v.begin()<< endl;
		//cout << idx << endl;
	}
	
	return 0;
}
