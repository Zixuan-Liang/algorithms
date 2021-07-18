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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return helper(l1, l2, 0);
    }
    
    ListNode* helper(ListNode* l1, ListNode* l2, int c) {
        ListNode* res = nullptr;
        if (l1 || l2 || c) {
            l1 = l1 ? l1 : new ListNode(0);
            l2 = l2 ? l2 : new ListNode(0);
            int total = l1->val + l2->val + c;
            res = new ListNode(total%10);
            res->next = helper(l1->next, l2->next, total/10);
        }
        return res;
    }
};