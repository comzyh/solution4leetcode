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
    ListNode *detectCycle(ListNode *head) {
        ListNode *a = head, *b = head;
        while (b != nullptr) {
            b = b->next;
            if (b != nullptr && b != a) {
                b = b->next;
            }
            if (b == a) {
                break;
            }
            a = a->next;
        }
        if (b == nullptr) {
            return nullptr;
        }
        int loop_leng = 1;
        for (b = b->next; b != a; b = b->next) {
            loop_leng ++;
        }
        a = head; 
        b = head;
        for (int i = 0; i < loop_leng; i++) {
            b = b->next;
        }
        while (a != b) {
            a = a->next;
            b = b->next;
        }
        return a;
    }
};
