using namespace std;

// Feel free to add new properties and methods to the class.
class MinMaxStack {
public:
	
	vector<int> stack;
	vector<int> maxStack;
	vector<int> minStack;
	
  int peek() {
    return stack.back();
  }

  int pop() {
		int currentValue = stack.back();
		int currentMaxValue = maxStack.back();
		int currentMinValue = minStack.back();
		
		if(currentValue == currentMaxValue){
			maxStack.pop_back();
		}
		
		if(currentValue == currentMinValue){
			minStack.pop_back();
		}
		
		stack.pop_back();
		
    return currentValue;
  }

  void push(int number) {
		stack.push_back(number);
		
		
		if(minStack.empty()){
			minStack.push_back(number);
		}else{
			int minCurrentValue = minStack.back();
			if(number <= minCurrentValue){
				minStack.push_back(number);
			}	
		}
		
		if(maxStack.empty()){
			maxStack.push_back(number);
		}else{
			int maxCurrentValue = maxStack.back();
			if(number >= maxCurrentValue){
				maxStack.push_back(number);
			}	
		}
		
  }

  int getMin() {
    return minStack.back();
  }

  int getMax() {
    return maxStack.back();
  }
};

