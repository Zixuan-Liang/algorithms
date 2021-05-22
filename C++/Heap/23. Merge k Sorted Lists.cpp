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
#include <utility>

struct ComparePair {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return a.first > b.first;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0) return nullptr;
        priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePair> heap;
        
        for (int i = 0; i < k; i++) {
            if (lists[i] == nullptr) {
                heap.push({INT_MAX, i});
            }
            else {
                heap.push({lists[i]->val, i});
            }
        }
        
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;
        while (heap.top().first != INT_MAX) {
            ListNode* newNode = new ListNode(heap.top().first);
            current->next = newNode;
            current = newNode;
            int i = heap.top().second;
            heap.pop();
            lists[i] = lists[i]->next;
            if (lists[i] == nullptr) {
                heap.push({INT_MAX, i});
            }
            else {
                heap.push({lists[i]->val, i});
            }
        }
        return dummy->next;
    }
};