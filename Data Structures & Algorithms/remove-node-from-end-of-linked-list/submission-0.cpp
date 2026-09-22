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
        ListNode* l = dummy;
        ListNode* r = head;

        while (n) {
            r = r->next;
            n--;
        }

        while (r) {
            l = l->next;
            r = r->next;
        }
        
        l->next = l->next->next;
        return dummy->next;
    }
};
