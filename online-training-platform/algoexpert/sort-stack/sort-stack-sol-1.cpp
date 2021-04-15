#include <vector>
using namespace std;

void insertInSortedStack(vector<int> &stack, int number){
	
	if(stack.empty() || stack.back() <= number){
		stack.push_back(number);
		return;
	}
	
	int top = stack.back();
	stack.pop_back();
	
	insertInSortedStack(stack, number);
	
	stack.push_back(top);
}

vector<int> sortStack(vector<int> &stack) {
  if(stack.empty()) {
		return stack;
	}
	
	int top = stack.back();
	stack.pop_back();
	
	sortStack(stack);
	
	insertInSortedStack(stack, top);
	
  return stack;
}

