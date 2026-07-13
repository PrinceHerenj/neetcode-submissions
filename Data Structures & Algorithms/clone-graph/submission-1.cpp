/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (not node) return nullptr;
        unordered_map<Node*, Node*> visited;
        visited[node] = new Node(node->val);

        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front(); q.pop();
            for (Node* n: curr->neighbors) {
                if(!visited.contains(n)) {
                    visited[n] = new Node(n->val);
                    q.push(n);
                }
                visited[curr]->neighbors.push_back(visited[n]);
            }
        }
        return visited[node];
    }
};
