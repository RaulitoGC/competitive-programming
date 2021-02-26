#include <any>
#include <vector>

using namespace std;

// Tip: You can use el.type() == typeid(vector<any>) to check whether an item is
// a list or an integer.
// If you know an element of the array is vector<any> you can cast it using:
//     any_cast<vector<any>>(element)
// If you know an element of the array is an int you can cast it using:
//     any_cast<int>(element)

int productSumHelper(vector<any> array, int depth){
	int size = array.size();
	int sum = 0;
	
	
	for(int i = 0 ; i < array.size() ; i++){
		auto element = array[i];
		if(element.type() == typeid(vector<any>)){
			sum += productSumHelper(any_cast<vector<any>>(element), depth + 1);
		}else{
			sum += any_cast<int>(element);
		}
	}
	
	return depth*sum;
}


//Time : O(n)
//Space : O(d)
int productSum(vector<any> array) {
	int sum = 0;
	for(int i = 0 ; i < array.size() ; i++){
		auto element = array[i];
		if(element.type() == typeid(vector<any>)){
			sum += productSumHelper(any_cast<vector<any>>(element), 2);
		}else{
			sum += any_cast<int>(element);
		}
	}
  return sum;
}

