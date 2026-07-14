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
    int dfs(TreeNode* node, int& maxp) {
        if (not node) return 0;

        int l = dfs(node->left, maxp), r = dfs(node->right, maxp);
        // check path passing thru every node in tree
        // l and r give max depth in left and right subtree
        // path thru node should try to include both in maxp calc
        // given that they are greater than 0
        l = max(l, 0), r = max(r, 0);
        maxp = max(maxp, node->val + l + r);
        return node->val + max(l, r); // return max depth
    }

    int maxPathSum(TreeNode* root) {
        int maxp = INT_MIN;
        dfs(root, maxp);
        return maxp;
    }
};