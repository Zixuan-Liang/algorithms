/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <queue>

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode();
        ListNode* curr = head;
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for (auto list : lists) {
            if (list) {
                pq.push({list->val, list});
            }
        }
        while (!pq.empty()) {
            auto [val, node] = pq.top();
            pq.pop();
            curr->next = new ListNode(val);
            curr = curr->next;
            node = node->next;
            if (node) {
                pq.push({node->val, node});
            }
        }
        return head->next;
    }
};