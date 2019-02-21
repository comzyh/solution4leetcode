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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) {
            return true;
        }
        ListNode *mid = head;
        ListNode *right = head;
        int len = 1;
        while (right->next != nullptr) {
            if (mid->next != nullptr) {
                mid = mid->next;
            }
            if (right->next != nullptr) {
                right = right->next;
                len ++;
            }
            if (right->next != nullptr) {
                right = right->next;
                len ++;
            }
        }
        if (len == 1) {
            return true;
        }
        right = mid;
        ListNode* re = mid->next;
        mid->next = nullptr;
        while (re != nullptr) {
            ListNode *t = re->next;
            re->next = right;
            right = re;
            re = t;
        }
        while (head != mid) {
            if (head->val != right->val) {
                return false;
            }
            head = head->next;
            right = right->next;
        }
        return true;
        
    }
};
