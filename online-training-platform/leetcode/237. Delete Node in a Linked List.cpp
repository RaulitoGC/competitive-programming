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
    void deleteNode(ListNode* node) {
        //cout << node->val << endl;
        ListNode* temp = node->next;
        while(true){
            node->val = temp->val;
            temp = temp->next;
            if(temp == NULL){
                node->next = NULL;
                break;
            }
            node = node->next;
        }
        
    }
};
