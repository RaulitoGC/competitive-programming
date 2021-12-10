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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* current = head;
        while(current != nullptr) {
            current = current->next;
            size++;
        }
        
        if(size == n) {
            return head->next;
        }
        
        int diff = size - n - 1;
        
        current = head;
        for(int i = 0 ; i < diff ; i++) {
            current = current->next;
        }
        
        ListNode* next = current->next;
        
        if(next == nullptr) {
            current->next = nullptr;
            return head;
        } else {
            current->next = next->next;
            return head;
        }
        
    }
};