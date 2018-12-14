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
    ListNode* partition(ListNode* head, int x) {
        ListNode **left = &head, *tmp;
        for (ListNode **p = &head; *p != nullptr;) {
            if ((*p)->val < x) {
                if (*p != *left) {
                    tmp = *p;
                    *p = (*p)->next;
                    tmp->next = *left;
                    *left = tmp;
                    left = &tmp->next;
                    continue;
                }
                left = &(*p)->next;                    
            }            
            p = &(*p)->next;
        }
        return head;
    }
};
