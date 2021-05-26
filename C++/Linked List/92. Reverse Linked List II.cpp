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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* s = new ListNode(0, head);
        ListNode* p1 = s, * p2, * p3, * p4;
        for (int i = 0; i < left-1; i++) p1 = p1->next;
        p2 = p1->next;
        p3 = p2; p4 = p2->next;
        for (int i = 0; i < right - left; i++) {
            ListNode* temp = p4->next;
            p4->next = p3;
            p3 = p4;
            p4 = temp;
        }
        p1->next = p3;
        p2->next = p4;
        return s->next;
    }
};