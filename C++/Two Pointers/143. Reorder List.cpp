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
        ListNode* p = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
    
    ListNode* combine(ListNode* p1, ListNode* p2) {
        if (!p2) return p1;
        p1->next = combine(p2, p1->next);
        return p1;
    }
    
    void reorderList(ListNode* head) {
        // find mid
        ListNode* dummy = new ListNode(0, head);
        ListNode* p1 = dummy, * p2 = dummy;
        while (p2 && p2->next) {
            p2 = p2->next->next;
            p1 = p1->next;
        }
        ListNode* right = p1->next;
        p1->next = nullptr;
        // reverse second half
        right = reverse(right);
        // combine first half and second half
        combine(head, right);
    }
};