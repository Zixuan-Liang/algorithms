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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* p = head;
        int len = 0;
        while (p) {
            len++;
            p = p->next;
        }
        if (len == 0) return head;
        k = k%len;
        if (k == 0) return head;
        
        ListNode* back = new ListNode(0, head);
        ListNode* front = head;
        for (int i = 0; i < k-1; i++) {
            front = front->next;
        }
        while (front->next) {
            front = front->next;
            back = back->next;
        }
        ListNode* res = back->next;
        back->next = nullptr;
        front->next = head;
        return res;
    }
};