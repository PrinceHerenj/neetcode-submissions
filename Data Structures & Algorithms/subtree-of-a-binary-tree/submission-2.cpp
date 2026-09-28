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
    bool isSameTree(TreeNode* n1, TreeNode* n2) {
        if (!n1 and !n2) return true;
        if (n1 and n2 and n1->val == n2->val) {
            return isSameTree(n1->left, n2->left) and isSameTree(n1->right, n2->right);
        }
        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        bool res = false;
        if (root->val == subRoot->val) res |= isSameTree(root, subRoot);
        if (root->left) res |= isSubtree(root->left, subRoot);
        if (root->right) res |= isSubtree(root->right, subRoot);
        return res;
    }
};
