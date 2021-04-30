#include <vector>
using namespace std;

vector<int> largestRange(vector<int> array) {
  
	int n = array.size();
	
	unordered_map<int,bool> numbers;
	
	for(int i = 0 ; i < n ; i++){
		numbers[array[i]] = true;
	}
	
	int maxSize = INT_MIN, leftNumberRange, rightNumberRange;
	
	for(int i = 0 ; i < n ; i++){
		int number = array[i];
		
		int leftNumber = number - 1;
		while(numbers[leftNumber]){
			numbers[leftNumber] = false;
			leftNumber--;
		}
		
		
		int rightNumber = number + 1;
		while(numbers[rightNumber]){
			numbers[rightNumber] = false;
			rightNumber++;
		}
		
		int size = rightNumber - leftNumber;
		if(size > maxSize){
			leftNumberRange = leftNumber + 1;
			rightNumberRange = rightNumber - 1;
			maxSize = size;
		}
	}
	
  return {leftNumberRange, rightNumberRange};
}

