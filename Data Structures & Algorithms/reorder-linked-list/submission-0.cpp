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
private:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr or head->next == nullptr) return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
public:
    void reorderList(ListNode* head) {
        ListNode *sp = head, *fp = head;
        while (fp->next and fp->next->next) {
            sp = sp->next;
            fp = fp->next->next;
        }

        ListNode *secondHalf = sp->next;
        sp->next = nullptr;

        secondHalf = reverseList(secondHalf);

        ListNode* p1 = head;
        ListNode* p2 = secondHalf;

        while (p2) {
            ListNode* next1 = p1->next;
            ListNode* next2 = p2->next;

            p1->next = p2;
            p2->next = next1;

            p1 = next1;
            p2 = next2;
        }

        
    }
};

