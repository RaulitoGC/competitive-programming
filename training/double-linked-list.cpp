#include<bits/stdc++.h>
using namespace std;

class Node {
public:
  int value;
  Node *prev;
  Node *next;

  Node(int value);
};

// Feel free to add new properties and methods to the class.
class DoublyLinkedList {
public:
  Node *head;
  Node *tail;

  DoublyLinkedList() {
    head = NULL;
    tail = NULL;
  }

  void setHead(Node *node) {
    if(head == NULL){
			head = node;
			tail = node;
			return;
		}
		insertBefore(head, node);
  }

  void setTail(Node *node) {
    if(tail == NULL){
			setHead(node);
			return;
		}
		insertAfter(tail, node);
  }

  void insertBefore(Node *node, Node *nodeToInsert) {
		//Verify corner case
		if(nodeToInsert == head && nodeToInsert == tail){
			return;
		}
		//Remove the node if it exist
		remove(nodeToInsert);
		
		// Update the next - prev nodeToInsert's nodes
		nodeToInsert->prev = node->prev;
		nodeToInsert->next = node;
		
		// verify node prev corner case
		if(node->prev == NULL){
			head = nodeToInsert;
		}else{
			node->prev->next = nodeToInsert;
		}
		
		// Update the before pointer
		node->prev = nodeToInsert;
  }

  void insertAfter(Node *node, Node *nodeToInsert) {
		//Verify corner case
  	if(nodeToInsert == head && nodeToInsert == tail){
			return;
		}
		//Remove the node if it exist
		remove(nodeToInsert);
		
		// Update the next - prev nodeToInsert's nodes
		nodeToInsert->prev = node;
		nodeToInsert->next = node->next;
		
		// verify node next corner case
		if(node->next == NULL){
			tail = nodeToInsert;
		}else{
			node->next->prev = nodeToInsert;
		}
		
		// Update the after pointer
		node->next = nodeToInsert;
  }

  void insertAtPosition(int position, Node *nodeToInsert) {
		if(position == 1){
			setHead(nodeToInsert);
			return;
		}
    
		Node* node = head;
		int idx = 1;
		while(idx != position && node != NULL){
			node = node->next;
			idx++;
		}
		
		if(node == NULL){
			setTail(nodeToInsert);
		}else{
			insertBefore(node, nodeToInsert);
		}
  }

  void removeNodesWithValue(int value) {
    Node* node = head;
		while(node != NULL){
			Node* nodeToRemove = node;
			node = node->next;
			if(nodeToRemove->value == value){
				remove(nodeToRemove);
			}
		}
  }

	void removeHelper(Node* node){
		if(node->prev != NULL){
			node->prev->next = node->next;
		}
		
		if(node->next != NULL){
			node->next->prev = node->prev;
		}
		node->prev = NULL;
		node->next = NULL;
	}
	
  void remove(Node *node) {
    if(node == head){
			head = head->next;
		}
		
		if(node == tail){
			tail = tail->prev;
		}
		removeHelper(node);
  }

  bool containsNodeWithValue(int value) {
    Node* current = head;
		while(current != NULL && current->value != value){
			current = current->next;
		}
    return current != NULL;
  }
};

