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
    ListNode* insertionSortList(ListNode* head) {
        ListNode **right = &head;
        while (*right != nullptr) {
            // find the position
            ListNode **left = &head;
            for (;(*right)->val > (*left)->val; left = &(*left)->next);
            // following code can't deal with *right == *left
            if (*left == *right) {
                right = &(*right)->next; // no swap, go ahead
                continue;
            }
            ListNode *right_next = (*right)->next;
            (*right)->next = *left;
            *left = *right;
            *right=right_next;
        }
        return head;
    }

};
