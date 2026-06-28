/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;

        // reached either of the nodes, return whichever has been found
        if (root->val == p->val || root->val == q->val)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // given nodes lie in either subtree, which means we are at LCA
        if (left && right)
            return root;
        
        // didn't find LCA, return whichever given node has been found
        return left ? left : right;
    }
};