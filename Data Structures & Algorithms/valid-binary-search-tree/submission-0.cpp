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
    typedef long long ll;
    bool isValid;

    bool isValidBST(TreeNode* root) {
        isValid = true;
        dfs(root);
        return isValid;
    }

    pair <ll, ll> dfs(TreeNode* root) {
        if (!root) return {LLONG_MAX, LLONG_MIN};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        ll val = root->val;

        if (left.second >= val || right.first <= val) {
            isValid = false;
        }

        return {min(val, left.first), max(val, right.second)};
    }
};