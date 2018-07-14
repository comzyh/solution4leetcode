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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA, *p2 = headB, *p3;
        while (p1 != nullptr && p2 != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
        }
        // get the shorter list
        ListNode **p;
        if (p1 == nullptr) {
            p1 = headA;
            p = &p2;
            p3 = headB;
        } else {
            p2 = headB;
            p = &p1;
            p3 = headA;
        }
        // align to pointer
        while (*p != nullptr) {
            *p = (*p)->next;
            p3 = p3->next;
        }
        *p = p3;
        while (p1 != nullptr && p2 != nullptr) {
            if (p1 == p2) {
                return p1;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return nullptr;
    }
};