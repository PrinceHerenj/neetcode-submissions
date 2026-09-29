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
    TreeNode* res;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        if (root == p) res = p;
        if (root == q) res = q;
        if ((p->val < root->val and q->val > root->val) or (p->val > root->val and q->val < root->val)) {
            return res = root;
        }
        if (p->val < root->val and q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        if (p->val > root->val and q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);

        return res;
    }
};
