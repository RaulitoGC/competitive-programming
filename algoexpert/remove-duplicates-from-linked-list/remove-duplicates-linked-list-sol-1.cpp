using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList *removeDuplicatesFromLinkedList(LinkedList *linkedList) {
  LinkedList* head = linkedList;
	if(linkedList == nullptr) return nullptr;
	
	int current = linkedList->value;
	LinkedList* next = linkedList->next;
	while(next != nullptr){
			if(next->value == current){
					linkedList->next = next->next;
					next = next->next;
			}else{
				current = next->value;
				linkedList = next;
				next = next->next;
			}
	}
	
  return head;
}

