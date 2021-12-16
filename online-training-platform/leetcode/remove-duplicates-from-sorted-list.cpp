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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) {
            return nullptr;
        }
        
        ListNode* prev = head;
        ListNode* current = head->next;
        while(current != nullptr) {
            ListNode* next = current->next;
            if(prev->val == current->val){
                prev->next = next;
            } else {
                prev = current;    
            }
            current = next;
        }
        
        return head;
    }
};