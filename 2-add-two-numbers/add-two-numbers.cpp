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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       int dammy = 0;
       ListNode* p = new ListNode(0);
       ListNode* head = p;

       while(l1 != NULL || l2 != NULL || dammy != 0) {
        if(l1 != NULL) {
            dammy += l1->val;
            l1 = l1->next;
        }
        if(l2 != NULL) {
            dammy += l2->val;
            l2 = l2->next;
        }
        p->next = new ListNode(dammy % 10);
        dammy /= 10;
        p = p->next;
       }
       return head->next; 
    }
};