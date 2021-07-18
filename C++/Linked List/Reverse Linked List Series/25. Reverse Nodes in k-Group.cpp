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
    // 获取链表长度
    int getLength(ListNode* head) {
        int res = 0;
        while (head) {
            res++;
            head = head->next;
        }
        return res;
    }
    
    // 翻转长度为k的链表
    ListNode* reverseK(ListNode* head, int k) {
        if (k == 1) return head;
        ListNode* temp = head->next;
        ListNode* res = reverseK(head->next, k-1);
        temp->next = head;
        return res;
    }
    
    // 先翻转前面k个，然后递归调用helper
    ListNode* helper(ListNode* head, int n, int k) {
        // 长度比k小，直接返回
        if (n < k) return head;
        // 先找出除去前面k个后剩下的头
        ListNode* restHead = head;
        for (int i = 0; i < k; i++) restHead = restHead->next;
        // 翻转前面k个
        ListNode* res = reverseK(head, k);
        // 递归调用
        head->next = helper(restHead, n-k, k);
        return res;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = getLength(head);
        return helper(head, n, k);
    }
};