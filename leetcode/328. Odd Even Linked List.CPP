/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return head;
        ListNode* a = head;
        ListNode* b = a->next;
        ListNode* headOdd = b;
        ListNode* c;
        if(b != NULL) c= b->next;
        else c = NULL;
        
        while(c != NULL){
            a->next = NULL;
            a->next = c;
            
            b->next = NULL;
            b->next = c->next;
            
            a = c;
            
            b = b->next;
            if(b != NULL) c = b->next;
            else c = NULL;
            
        }
         
        a->next = headOdd;
        return head;
    }
};
