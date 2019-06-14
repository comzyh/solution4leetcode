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
    ListNode* swapPairs(ListNode* head) {
        ListNode **h = &head;
        while ((*h) != nullptr && (*h)->next != nullptr) {
            ListNode *l = *h;
            ListNode *r = l->next;

            l->next = r->next;
            r->next = l;

            *h = r;
            h = &(l->next);
        }
        return head;
    }
};
