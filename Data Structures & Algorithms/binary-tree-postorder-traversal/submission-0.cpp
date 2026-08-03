/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st({root});
        stack<bool> visit({false});
        
        while (!st.empty()) {
            TreeNode* curr = st.top(); st.pop();
            bool visited = visit.top(); visit.pop();
            if (curr) {
                if (visited) {
                    res.push_back(curr->val);
                } else {
                    st.push(curr);
                    visit.push(true);
                    st.push(curr->right);
                    visit.push(false);
                    st.push(curr->left);
                    visit.push(false);
                    
                }
            }
        }

        return res;
    }
};