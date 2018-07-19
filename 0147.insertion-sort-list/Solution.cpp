#include <cstdio>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
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
        for (;*right != nullptr;right = &(*right)->next) {
            // find the position
            ListNode **left = &head;
            for (;(*right)->val > (*left)->val; left = &(*left)->next);
            // following code can't deal with *right == *left
            if (*left == *right) {
                continue;
            }
            ListNode *right_next = (*right)->next;
            (*right)->next = (*left)->next;
            *left = *right;
            *right=right_next;
        }
        return head;
    }

};

int main() {
    ListNode a(4);
    ListNode b(2);
    ListNode c(2);
    ListNode d(2);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    ListNode *input = &a;
    auto s = Solution();
    ListNode* ans = s.insertionSortList(input);
}

