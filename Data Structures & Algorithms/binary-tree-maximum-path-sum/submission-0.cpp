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
    int res;
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int leftMax = max(dfs(root->left), 0);
        int rightMax = max(dfs(root->right), 0);

        // if taking current root as splitting point has res values greater
        // update res
        res = max(res, root->val + leftMax + rightMax);

        // return from current, value + (max from left and right)
        return root->val + max(leftMax, rightMax);
    }

    int maxPathSum(TreeNode* root) {
        res = root->val;
        dfs(root);
        return res;
    }
};
