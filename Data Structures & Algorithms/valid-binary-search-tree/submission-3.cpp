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
    bool isValidBST(TreeNode* root, int mn=INT_MIN, int mx=INT_MAX) {
        if (not root)
            return true;
        
        bool l = isValidBST(root->left, mn, root->val);
        bool r = isValidBST(root->right, root->val, mx);

        return (mn < root->val and root->val < mx) and l and r;
    }
};
