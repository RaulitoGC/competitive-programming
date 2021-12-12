/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr) {
            return false;
        }
        ListNode* first = head;
        ListNode* second = head->next;
        
        while(true) {
            if(first == nullptr || second == nullptr) {
                return false;
            }
            
            if(first == second) {
                return true;
            }
            
            first = first->next;
            
            if(second->next == nullptr) {
                return false;
            }
            
            second = second->next->next;
        }
        
        return false;
    }
};