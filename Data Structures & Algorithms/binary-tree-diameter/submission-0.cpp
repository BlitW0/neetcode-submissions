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
    int dfs(TreeNode* root, int& dia) {
        // returns max depth at node n
        if (not root) return 0;

        int l = dfs(root->left, dia), r = dfs(root->right, dia);
        // path with max len going through n = l + r
        // dia = max of path going through any node n
        dia = max(dia, l + r);
        return 1 + max(l, r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        dfs(root, dia);
        return dia;
    }
};