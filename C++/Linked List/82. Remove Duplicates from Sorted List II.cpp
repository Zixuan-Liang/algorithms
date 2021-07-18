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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* p1 = dummy, * p2 = head;
        while (p2) {
            if (!p2->next || p2->val != p2->next->val) {
                p1->next = p2;
                p1 = p2;
                p2 = p2->next;
            }
            else {
                while (p2->next && p2->val == p2->next->val) {
                    p2 = p2->next;
                }
                p2 = p2->next;
            }
        }
        p1->next = nullptr;
        return dummy->next;
    }
};