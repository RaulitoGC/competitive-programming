using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList *sumOfLinkedLists(LinkedList *linkedListOne,
                             LinkedList *linkedListTwo) {
  
	LinkedList* linkedListSum = nullptr;
	LinkedList* head = nullptr;
	int first, second, currentSum, value, carry = 0;
	while(linkedListOne != nullptr && linkedListTwo != nullptr){
		first = linkedListOne->value;
		second = linkedListTwo->value;
		currentSum = first + second + carry;
		value = currentSum%10;
		if(currentSum >= 10){
			carry = currentSum/10;	
		}else{
			carry = 0;
		}
		cout << value << endl;
		LinkedList* current = new LinkedList(value);
		if(linkedListSum == nullptr){
			linkedListSum = current;
			head = linkedListSum;
		}else{
			linkedListSum->next = current;
			linkedListSum = linkedListSum->next;
		}
		
		linkedListOne = linkedListOne->next;
		linkedListTwo = linkedListTwo->next;
		
		if(linkedListOne == nullptr && linkedListTwo != nullptr){
			while(linkedListTwo != nullptr){
				second = linkedListTwo->value;
				currentSum = second + carry;
				value = currentSum%10;
				
				if(currentSum >= 10){
					carry = currentSum/10;	
				}else{
					carry = 0;
				}
				
				current = new LinkedList(value);
				linkedListSum->next = current;
				linkedListSum = linkedListSum->next;
				
				linkedListTwo = linkedListTwo->next;
			}
		}else if(linkedListOne != nullptr && linkedListTwo == nullptr){
			while(linkedListOne != nullptr){
				
				first = linkedListOne->value;
				currentSum = first + carry;
				value = currentSum%10;
				
				if(currentSum >= 10){
					carry = currentSum/10;	
				}else{
					carry = 0;
				}
				
				current = new LinkedList(value);
				linkedListSum->next = current;
				linkedListSum = linkedListSum->next;
				
				linkedListOne = linkedListOne->next;
			}
		} else if(linkedListOne == nullptr && linkedListTwo == nullptr && carry != 0){
			linkedListSum->next = new LinkedList(carry);
			linkedListSum = linkedListSum->next;
		}
	}
	
  return head;
}