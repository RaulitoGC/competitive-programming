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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1 == nullptr && list2 == nullptr) {
            return nullptr;
        }
        
        if(list1 == nullptr) {
            return list2;
        }
        
        if(list2 == nullptr) {
            return list1;
        }
        
        ListNode* prev = new ListNode();
        ListNode* current = prev;
        while(list1 != nullptr && list2 != nullptr) {
            int v1 = list1->val;
            int v2 = list2->val;
            cout << v1 << " - " << v2 << endl;
            int minValue;
            if(v1 < v2) {
                minValue = v1;
                list1 = list1->next;
            } else {
                minValue = v2;
                list2 = list2->next;
            }
            
            ListNode* next = new ListNode(minValue);
            current->next = next;
            current = current->next;
        }
        
        while(list1 != nullptr) {
            int value = list1->val;
            ListNode* next = new ListNode(value);
            current->next = next;
            current = current->next;
            list1 = list1->next;
        }
        
        while(list2 != nullptr) {
            int value = list2->val;
            ListNode* next = new ListNode(value);
            current->next = next;
            current = current->next;
            list2 = list2->next;
        }
        
        return prev->next;
    }
};