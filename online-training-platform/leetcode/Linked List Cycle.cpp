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
        if(head == nullptr) return false;
        ListNode* first = head;
        ListNode* second = head->next;
        bool res = false;
        while(true){
            if(first == nullptr || second == nullptr){
                res = false;
                break;
            } 
            if(first == second){
                res = true;
                break;
            } 
            first = first->next;
            if(second->next != nullptr){
                second = (second->next)->next;    
            }else{
                res = false;
                break;
            }
            
        }
    
        
        return res;
    }
};
