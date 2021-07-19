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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy, *front = head, *back = head;
        for (int i = 0; i < n-1; i++) front = front->next;
        while (front->next) {
            prev = back;
            back = back->next;
            front = front->next;
        }
        prev->next = back->next;
        return dummy->next;
    }
};