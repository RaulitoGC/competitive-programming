using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    this->next = nullptr;
  }
};

int getLinkedeListSize(LinkedList *head);
LinkedList* getSecondHalf(int n, LinkedList *head);
LinkedList* reverseLinkedList(LinkedList *head);
bool verifyEqualityInSecondList(LinkedList* first, LinkedList* second);

bool linkedListPalindrome(LinkedList *head) {
  int n = getLinkedeListSize(head);
	
	if(n == 1){
		return true;
	}
	cout << n << endl;
	LinkedList* secondHalf = getSecondHalf(n, head);
	LinkedList* secondHalfReverse = reverseLinkedList(secondHalf);
	
  return verifyEqualityInSecondList(head, secondHalfReverse);
}

int getLinkedeListSize(LinkedList* head){
	int n = 0;
	LinkedList* current = head;
	while(current != nullptr){
		current = current->next;
		n++;
	}
	
	return n;
}
LinkedList* getSecondHalf(int n, LinkedList *head){
	LinkedList* current = head;
	int size = n / 2 - 1;
	
	if(n % 2 != 0) {
		size++;
	}
	while(size--){
		current = current->next;
	}
	cout <<"current : " << current->value << endl;
	cout <<"current next: " << current->next->value << endl;
	LinkedList* secondHalfHead = current->next;
	current->next = nullptr;
	cout <<"second : " << secondHalfHead->value << endl;
	return secondHalfHead;
}

LinkedList* reverseLinkedList(LinkedList *head){
	LinkedList* current = head;
	LinkedList* prev = nullptr;
	
	while(current != nullptr){
		LinkedList* next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	
	cout << " prev : " << prev->value << endl;
	return prev;
}

bool verifyEqualityInSecondList(LinkedList* first, LinkedList* second){
	while(second != nullptr){
		cout << first->value << " -- " << second->value << endl;
		if(first->value != second->value){
			return false;
		}
		first = first->next;
		second = second->next;
	}
	
	return true;
}

