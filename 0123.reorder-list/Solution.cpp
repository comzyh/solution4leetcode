reorder-list/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) {
            return;
        }
        ListNode **ptrr = &head;
        ListNode **ptrl = &head;
        while ((*ptrr)->next != nullptr) {
            ptrr = &(*ptrr)->next;
            ptrl = &(*ptrl)->next;
            if ((*ptrr)->next == nullptr) {
                break;
            }
            ptrr = &(*ptrr)->next;
            if ((*ptrr)->next == nullptr) {
                // keep the left part longer than the right part
                ptrl = &(*ptrl)->next;
            }
        }

        //reverse the right part
        ListNode *rhead = nullptr;
        for (ListNode *i = *ptrl;  i != nullptr; ) {
            ListNode *j = i->next;
            i->next = rhead;
            rhead = i;
            i = j;
        }
        *ptrl = nullptr; // break the left linked list

        // join two linkedlist
        for (ListNode *i = head; i != nullptr;) {
            ListNode *in = i->next;
            i->next = rhead;
            i = in;
            if (rhead != nullptr) {
                ListNode *rn = rhead->next;
                rhead->next = in;
                rhead = rn;
            }
        }
    }
};