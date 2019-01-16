/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <utility>
#include <queue>
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = nullptr;
        ListNode **tail = &head;
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*> >, greater<pair<int, ListNode*> > > q;
        for (size_t i = 0; i < lists.size(); i++) if (lists[i])  {
                q.push(make_pair(lists[i]->val, lists[i]));
            }
        while (!q.empty()) {
            ListNode *h = q.top().second;
            q.pop();
            if (h->next) {
                q.push(make_pair(h->next->val, h->next));
            }
            *tail = h;
            tail = &((*tail)->next);
        }
        return head;

    }
};
