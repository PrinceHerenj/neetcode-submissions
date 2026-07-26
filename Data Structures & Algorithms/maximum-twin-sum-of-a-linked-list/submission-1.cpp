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
        stack<int> st;
        ListNode* cur = head;
        while (cur != nullptr) {
            st.push(cur->val);
            cur = cur->next;
        }

        cur = head;
        ListNode* fp = head;
        int res = INT_MIN;
        while (fp != nullptr and fp->next != nullptr) {
            res = max(res, cur->val + st.top());
            st.pop();
            cur = cur->next;
            fp = fp->next->next;
        }
        return res;
    }
};