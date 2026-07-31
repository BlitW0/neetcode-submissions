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
    int dfs(TreeNode* root, int& maxPath) {
        if (!root)
            return INT_MIN;
        
        int l = dfs(root->left, maxPath);
        int r = dfs(root->right, maxPath);
        int val = root->val;

        maxPath = max(maxPath, val + max(0, l) + max(0, r));

        if (max(l, r) > 0)
            val += max(l, r);
        return val;
    }

    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        dfs(root, maxPath);
        return maxPath;
    }
};
