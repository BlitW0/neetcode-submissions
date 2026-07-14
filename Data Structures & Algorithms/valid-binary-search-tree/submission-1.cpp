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
    bool isValidBST(TreeNode* root, long mn=LONG_MIN, long mx=LONG_MAX) {
        if (not root) return true;

        // root should lie in range (mn, mx) and
        // both left and right subtree should be valid bst
        // left subtree can't have val greater than root
        // right subtree can't have val lesser than root
        return (mn < root->val and root->val < mx) 
            and isValidBST(root->left, mn, root->val) 
            and isValidBST(root->right, root->val, mx);
    }
};