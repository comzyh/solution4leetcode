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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode **h = &head;
        while (*h != nullptr) {
            if ((*h)->next != nullptr && (*h)->next->val == (*h)->val) {
                ListNode *t = (*h)->next;
                while (t != nullptr && t->val == (*h)->val) {
                    t = t->next;
                }
                *h = t;
            } else {
                h = &(*h)->next;
            }
        }
        return head;
    }
};
