class MyLinkedList {
    public:
    
    struct SinglyListNode {
        int val;
        SinglyListNode *next;
        SinglyListNode(int x) : val(x), next(NULL) {}
    };
    
    SinglyListNode *head;
    
    int MAX = 1000;
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        
        
        if(index < 0 || index > MAX) return -1;
        
        SinglyListNode *current = head;
        int i = 0;
        
        // while(current != NULL){
        //     cout<< current->val<<" ";
        //     current = current->next;
        // }
        // cout<<endl;
        // current = head;
        
        while(current != NULL && i != index){
            i++;
            current = current->next;
        }
        
        if(index == i && current != NULL) return current->val;
        else return -1;
        
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        
        SinglyListNode *current = head;
        SinglyListNode *newValue = new SinglyListNode(val);
        
        newValue->next = current;
        head = newValue;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        
        SinglyListNode *newValue = new SinglyListNode(val);
        if(head == NULL){
            head = newValue;
            return;
        }
        
        SinglyListNode *current = head;
        
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newValue;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        
        if(index > MAX) return;
        if(index <= 0){
            addAtHead(val);
            return;
        } 
        
        SinglyListNode *prev = head;
        SinglyListNode *current = NULL;
        if(prev != NULL) current = prev->next;
        SinglyListNode *newValue = new SinglyListNode(val);
        
        int i = 1;
        while(i != index && current != NULL){
            i++;
            prev = current;
            current = current->next;
        }
        
        if(prev != NULL) prev->next = newValue;
        newValue->next = current;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        
        if(index < 0 || index > MAX) return;
        SinglyListNode *prev = head;
        SinglyListNode *current = NULL;
        if(prev != NULL) current = prev->next;
        
        if(index == 0){
            prev->next = NULL;
            prev = NULL;
            head = current;
        }
        
        int i = 1;
        while(i != index && current != NULL){
            i++;
            prev = current;
            current = current->next;
        }
    
        if(prev != NULL){
            if(current != NULL){
                prev->next = current->next;        
                current->next = NULL;
                current = NULL;
            }
        }
    
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */