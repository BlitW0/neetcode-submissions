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
    int goodNodes(TreeNode* root, int maxInPath=INT_MIN) {
        if (not root)
            return 0;
        
        int newmx = max(maxInPath, root->val);
        int l = goodNodes(root->left, newmx);
        int r = goodNodes(root->right, newmx);

        return (root->val >= maxInPath) + l + r;
    }
};
