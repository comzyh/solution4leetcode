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
    bool hasCycle(ListNode *head) {
        while (head != nullptr) {
            if (head->next == head) {
                return true;
            }
            ListNode *next = head->next;
            head->next = head;
            head = next;
        }
        return false;
    }
};