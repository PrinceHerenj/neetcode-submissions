/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;
        unordered_map<Node*, Node*> hash;
        while (curr) {
            hash[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;
        
        while (curr) {
            hash[curr]->next = hash[curr->next];
            hash[curr]->random = hash[curr->random];
            curr = curr->next;

        }

        return hash[head];
    }
};
