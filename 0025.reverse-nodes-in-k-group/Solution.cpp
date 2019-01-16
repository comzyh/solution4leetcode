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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k < 2) {
            return head;
        }
        ListNode *ret = nullptr;
        ListNode **current = &head;
        while (*current != nullptr) {
            ListNode *thead = *current;
            int len = 0;
            for (ListNode *p = thead; p != nullptr; p = p->next) {
                len ++;
            }
            if (len < k) {
                if (ret == nullptr) {
                    return head;
                }
                break;
            }
            ListNode *tail = thead;
            ListNode *rhead = tail->next;
            for (int j = 1; j < k; j++) {
                ListNode *old_tail = tail;
                tail = rhead;
                rhead = rhead->next;
                tail->next = old_tail;
            }
            thead->next = rhead;
            if (ret == nullptr) {
                ret = tail;
            }
            *current = tail;
            current = &thead->next;
        }
        return ret;
    }
};
