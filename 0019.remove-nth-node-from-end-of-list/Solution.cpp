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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode ** ptrr = &head;
        while (--n) {
            ptrr = &((*ptrr)->next);
        }
        ListNode **ptrl = &head;
        while((*ptrr)->next != nullptr){
            ptrr = &((*ptrr)->next);
            ptrl = &((*ptrl)->next);
        }
        *ptrl = (*ptrl)->next;
        return head;
    }
};