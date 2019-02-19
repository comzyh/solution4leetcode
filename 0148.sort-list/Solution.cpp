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
    ListNode* sortList(ListNode* start, ListNode *end) {
        ListNode *mid = start, *right = start;
        while(right->next != end) {
            if (mid->next != end) {
                mid = mid->next;
            }
            if (right->next != end) {
                right = right->next;
            }
            if (right->next != end) {
                right = right->next;
            }
        }
        if (start == right) {
            start->next = nullptr;
            return start;
        }
        ListNode *a = sortList(start, mid);
        ListNode *b = sortList(mid, end);
        ListNode *ans;
        ListNode **tail = &ans;
        while(a != nullptr || b != nullptr) {
            if (a != nullptr && (b == nullptr || a->val < b->val)) {
                *tail = a;
                tail = &(a->next);
                a = a->next;
            } else {
                *tail = b;
                tail = &(b->next);
                b = b->next;
            }
        }
        *tail = nullptr;
        return ans;
        
    }
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        return sortList(head, nullptr);
    }
};
