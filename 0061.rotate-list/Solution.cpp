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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode **ptrr = &head;
        int len = 1;
        while(k--) {
            if ((*ptrr)->next) {
                ptrr = &(*ptrr)->next;
                len ++;
            } else {
                ptrr = &head;
                k = k % len;
                while(k--) {
                    ptrr = &(*ptrr)->next;
                }
                break;
            }
        }
        ListNode **ptrl = &head;
        if (ptrl == ptrr) {
            return head;
        }
        while ((*ptrr)->next != nullptr) {
            ptrr = &(*ptrr)->next;
            ptrl = &(*ptrl)->next;
        }
        (*ptrr)->next = head;
        ListNode *ans = (*ptrl)->next;
        (*ptrl)->next = nullptr;
        return ans;
    }
};