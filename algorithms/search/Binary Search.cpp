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
	return target < x;
}

// Upper bound in c++ : upper_bound() is a standard library 
// function in C++ defined in the header . It returns an 
// iterator pointing to the first element in the 
// range [first, last) that is greater than value, or last 
// if no such element is found. The elements in the range shall 
// already be sorted or at least partitioned with respect to val.

// bs_upper_bound : return the position which has a value greater than target
// or last if element is found
int bs_upper_bound(vector<int> S, int target){
	// First item of the set S
	int low = 0;
	// Last item of the set S
	int high = S.size() - 1;

	// We use < since the search space can be [a,b] and we are looking for a upper_value
	while(low < high){
		// In order to rounding down make median = l + (h - l)/2
		int median = low + (high - low)/2;
		//cout << low << " -- "<< high << endl;

		// In this case the predicate is "Is S[median] greater than target?"
		// Since we are sure that all the values to the right are greater than the target
		// and we are searching for the first value greater than target
		// We can move to the left side in order to verify if there is at least one more value
		// thant can satisfy the predicate p2
		// we need to include median since it could be our first value for when 
		// p2 is true
		if(p2(S[median], target)){
			high = median;
		// Since we are sure that predicate p2(x) is false, we can decide what is 
		// our new search space. For this case if target is greater or equal than the S[median]
		// it means that our new search space is:
		// S[median] = 3
		// [1,1,1,1,3,3,3,3] -> Search space [0, 7]
		// [1,1,1,1,-,-,-,-] -> Search space [0, 4]
		// we do not need to include median, since it is false for p2 predicate
		}else {
			low = median + 1;
		}
		// Complain :  p(x) is false for all x in S!
		// if(!p2(S[low], target)){
			//return low;
		//}
	}

	// When we are out of search space, we can return low since, we are looking for the lower_bound position
	return low;
} 


bool p1(int x, int target){
	return target <= x;
}

// Lower Bound in C++ = The lower_bound() method in C++ is used to return an 
// iterator pointing to the first element in the range [first, last) which has 
// a value not less than val. This means that the function returns the index 
// of the next smallest number just greater than or equal to that number. 
// If there are multiple values that are equal to val, lower_bound() returns 
// the index of the first such value.

// Lower_Bound: return the position which has a value not less than target
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

		// In this case the predicate is "Is target less or equal to s[median]?"
		// Since we know that or s[median] value is greater or equal that the target value
		// We can move to the left side in order to verify if there is at least one more value 
		// thant can satisfy the predicate p1
		// We need to include median since it could be our first value whenn p1 is true
		if(p1(S[median], target)){
			high = median;
		// Since we are sure that predicate p(x) is false, we can decide what is 
		// our new search space. For this case if target is greater than the S[median]
		// it means that our new search space is the right side:
		// S[median] = 2
		// [1,2,2,2,2,2,2,2,2,2,2,2] -> Search space [0, 12]
		// [-,-,-,-,-,-,2,2,2,2,2,2] -> Search space [0, 5]
		// We do not need to include median, since we know that p1 for median is false
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
	v.push_back(2);
	v.push_back(3);
	v.push_back(3);
	v.push_back(3);
	v.push_back(3);
	v.push_back(7);

	//v.push_back(3);
	// v.push_back(4);
	// v.push_back(4);
	// v.push_back(4);
	// v.push_back(4);

	int num;
	while(cin >> num){
		//int idx = bs(v, num);
		
		// auto lower_it = lower_bound(v.begin(), v.end(), num);
		// auto custom_lower_idx = bs_lower_bound(v, num);

		auto upper_it = upper_bound(v.begin(), v.end(), num);
		auto custom_upper_idx = bs_upper_bound(v, num);
		// cout << "custom upper bound " << custom_lower_idx << endl;
		// cout <<"lower bound = " << lower_it  - v.begin()<< endl;
		cout <<"custom upper bound = " << custom_upper_idx << endl;
		cout <<"upper bound = " << upper_it  - v.begin() << endl;
	}
	
	return 0;
}
