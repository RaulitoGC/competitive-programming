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
    ListNode* middleNode(ListNode* head) {
        ListNode *current = head;
        int count = 0;
        while(current && current->next){
            count++;
            current = current->next;
        }
        //cout<< "count --> "<< count << endl;
        current = head;
        count = (count/2) + (count%2);
        for(int i = 0; i < count ; i++){
            current = current->next;
        }
        return current;
    }
};