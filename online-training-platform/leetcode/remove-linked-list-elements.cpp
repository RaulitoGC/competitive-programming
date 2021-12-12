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
    
    ListNode* removeElements(ListNode* head, int val) {
        
        if(head == nullptr) {
            return nullptr;
        }
        
        ListNode* sentinel = new ListNode();
        ListNode *prev = sentinel, *current = head, *nodeToRemove = nullptr;
        prev->next = current;
    
        while(current != nullptr) {
            if(current->val == val) {
                prev->next = current->next;
                nodeToRemove = current;
            } else {
                prev = current;
            }
            
            current = current->next;
            
            if(nodeToRemove != nullptr) {
                delete nodeToRemove;
                nodeToRemove = nullptr;
            }
        }
        
        return sentinel->next;
    }
};