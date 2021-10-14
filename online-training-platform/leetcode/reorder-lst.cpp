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
  
    ListNode* reverse(ListNode* head) { 
      ListNode* prev = nullptr;
      ListNode* current = head;
      while(current != nullptr) {
        ListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
      }
      
      return prev;
    }
  
    void reorderList(ListNode* head) {
      ListNode* t = head;
      int n = 0;
        
      while(t != nullptr) {
        n++;
        t = t->next;
      }
      
      if(n < 3) return;
      
      int middle = n / 2;
      t = head;
      while(middle >= 0){
        t = t->next;
        middle--;
      }
      ListNode* t2 = head;
      while(t != nullptr){
        t = t->next;
        t2 = t2->next;
      }
      //cout << t2->val << endl;
      ListNode* reversed = reverse(t2->next);
      t2->next = nullptr;
      cout << reversed->val << endl;
      t = head;
      while(t != nullptr && reversed != nullptr) {
        ListNode* tNext = t->next;
        ListNode* rNext = reversed->next;
        t->next = reversed;
        reversed->next = tNext;
        
        t = tNext;
        reversed = rNext;
      }
        
    }
};