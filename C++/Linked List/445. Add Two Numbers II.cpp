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
    
    ListNode* reverse(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* res = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return res;
    }
    
    ListNode* add(ListNode* p1, ListNode* p2) {
        ListNode* res = new ListNode();
        ListNode* curr = res;
        int carry = 0;
        while (p1 || p2 || carry) {
            if (!p1) p1 = new ListNode(0);
            if (!p2) p2 = new ListNode(0);
            int sum = p1->val + p2->val + carry;
            int digit = sum % 10;
            carry = sum / 10;
            ListNode* node = new ListNode(digit);
            curr->next = node;
            curr = node;
            p1 = p1->next;
            p2 = p2->next;
        }
        return res->next;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode* res = add(l1, l2);
        return reverse(res);
    }
};