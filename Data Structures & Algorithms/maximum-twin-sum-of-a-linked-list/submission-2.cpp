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
    int pairSum(ListNode* head) {
        if (!head->next->next) return head->val + head->next->val;
        ListNode* prev, *curr, *next, *fp;
        prev = nullptr; curr = head; fp = head;
        while (fp != nullptr and fp->next != nullptr) {
            fp = fp->next->next;
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        int res = 0;
        while (curr) {
            res = max(res, prev->val + curr->val);
            prev = prev->next;
            curr = curr->next;
        }     

        return res;
    }
};