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
        ListNode* prev = nullptr, * temp;
        while (head) {
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    
    
    ListNode* median(ListNode* head) {
        ListNode* fast = head, * slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    bool isPalindrome(ListNode* head) {
        
        if (!head) return true;
        ListNode* fisrtEnd = median(head);
        ListNode* secondStart = reverse(fisrtEnd->next);
        ListNode* p1 = head, * p2 = secondStart;
        bool equal = true;
        while (equal && p2) {
            if (p1->val != p2->val) equal = false;
            p1 = p1->next;
            p2 = p2->next;
        }
        // fisrtEnd->next = reverse(secondStart); // Optional: restore the second half which is reversed.
        return equal;
    }
};