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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return backtrack(root, targetSum);
    }

    bool backtrack(TreeNode* root, int targetSum) {
        if (!root) return false;
        targetSum -= root->val;

        if (!root->left && !root->right && targetSum == 0) return true;
        if (backtrack(root->left, targetSum)) return true;
        if (backtrack(root->right, targetSum)) return true;
        return false;
        
    }
};