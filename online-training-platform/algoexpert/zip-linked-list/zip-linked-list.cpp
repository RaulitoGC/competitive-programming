using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList* getSecondHalf(LinkedList* root);
LinkedList* reverseLinkedList(LinkedList* root);
LinkedList* mergeLinkedList(LinkedList* first, LinkedList* second);

LinkedList *zipLinkedList(LinkedList *linkedList) {
	if(linkedList == nullptr){
		return linkedList;
	}
	
	LinkedList* firstHalf = linkedList;
	LinkedList* secondHalf = getSecondHalf(linkedList);
	
	LinkedList* reverseSecondHalf = reverseLinkedList(secondHalf);
	
	return mergeLinkedList(firstHalf, reverseSecondHalf);
}

LinkedList* getSecondHalf(LinkedList* root){
	LinkedList* fast  = root;
	LinkedList* slow  = root;
	
	while(fast != nullptr && fast->next != nullptr){
		slow = slow->next;
		fast = fast->next->next;
	}
	
	LinkedList* secondHalfHead = slow->next;
	slow->next = nullptr;
	
	return secondHalfHead;
}

LinkedList* reverseLinkedList(LinkedList* root){
	LinkedList* prev = nullptr;
	LinkedList* current = root;
	
	while(current != nullptr){
		LinkedList* nextNode = current->next;
		current->next = prev;
		prev = current;
		current = nextNode;
	}
	
	return prev;
}

LinkedList* mergeLinkedList(LinkedList* first, LinkedList* second){
	LinkedList* firstIterator = first;
	LinkedList* secondIterator = second;
	
	while(secondIterator != nullptr){
		LinkedList* firstNext = firstIterator->next;
		LinkedList* secondNext = secondIterator->next;
		
		firstIterator->next = secondIterator;
		secondIterator->next = firstNext;
		
		firstIterator = firstNext;
		secondIterator = secondNext;
	}
	
	return first;
}

