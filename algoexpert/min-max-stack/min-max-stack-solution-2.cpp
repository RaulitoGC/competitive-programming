using namespace std;

// Feel free to add new properties and methods to the class.
class MinMaxStack {
public:
	vector<int> stack;
	int minValue;
	int maxValue;
	
  int peek() {
    int valueToPeek = stack.back();
		
		if(valueToPeek < minValue){
			valueToPeek = minValue;
		}
		
		if(valueToPeek > maxValue){
			valueToPeek = maxValue;
		}
		
    return valueToPeek;
  }

  int pop() {
		
    int valueAtTop = stack.back();
		int valueToRemove = valueAtTop;
		
		if(valueAtTop < minValue){
			valueToRemove = minValue;
			minValue = 2*minValue - valueAtTop;
		}
		
		if(valueToRemove > maxValue){
			valueToRemove = maxValue;
			maxValue = 2*maxValue - valueAtTop;
		}
		
		stack.pop_back();

    return valueToRemove;
  }

  void push(int number) {
		int valueToInsert = number;
		if(stack.empty()){
			minValue = number;
			maxValue = number;
		}else{
			if(number > maxValue){
				valueToInsert = 2*number - maxValue;
				maxValue = number;
			}
		
			if(number < minValue){
				valueToInsert = 2*number - minValue;
				minValue = number;
			}
		}
		// cout << "value to insert" <<valueToInsert << endl;
		// cout << "vmin" <<minValue << endl;
		// cout << "max" <<maxValue << endl;
		stack.push_back(valueToInsert);
  }

  int getMin() {
    return minValue;
  }

  int getMax() {
    return maxValue;
  }
};

