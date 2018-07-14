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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head_placeholder(0);
        ListNode *head = &head_placeholder;
        ListNode **tail = &head->next;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                *tail = l1;
                tail = &l1->next;
                l1 = l1->next;
            } else {
                *tail = l2;
                tail = &l2->next;
                l2 = l2->next;
            }
        }
        if (l1 == nullptr) {
            *tail = l2;
        }
        if (l2 == nullptr) {
            *tail = l1;
        }
        return head->next;
    }
};
