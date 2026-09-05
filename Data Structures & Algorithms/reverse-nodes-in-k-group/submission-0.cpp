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
    ListNode* reverseList(ListNode* head, ListNode* end) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != end) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* advance(ListNode* node, int k) {
        if (!node) return nullptr;
        while (k--) {
            if (!node->next) return nullptr;
            node = node->next;
        }

        return node;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* curr = dummy;
        ListNode* groupPrev = dummy;

        while (curr) {
            ListNode* kth = advance(groupPrev, k);
            if (!kth) break;
            ListNode* groupNext = kth->next;
            ListNode* groupStart = groupPrev->next;
            reverseList(groupStart, groupNext);
            groupPrev->next = kth;
            groupStart->next = groupNext;
            groupPrev = groupStart;
        }

        return dummy->next;
    }
};
