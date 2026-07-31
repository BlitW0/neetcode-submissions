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
    unordered_map <int, int> inIdx;

    TreeNode* dfs(vector<int>& preorder, int& preIdx, int l, int r) {
        // this returns the root node of range [l, r] in inorder
        if (l > r)
            return nullptr;
        
        TreeNode* root = new TreeNode();
        root->val = preorder[preIdx++];
        int mid = inIdx[root->val];

        root->left = dfs(preorder, preIdx, l, mid - 1);
        root->right = dfs(preorder, preIdx, mid + 1, r);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size(), preIdx = 0;
        for (int i = 0; i < n; i++)
            inIdx[inorder[i]] = i;
        return dfs(preorder, preIdx, 0, n - 1);
    }
};
