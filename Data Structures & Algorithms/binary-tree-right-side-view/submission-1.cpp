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
    vector<int> rightSideView(TreeNode* root) {
        vector <int> view;
        if (not root) return view;

        queue <TreeNode*> q;
        q.push(root);
        while (not q.empty()) {
            int size = q.size(); // num nodes on this level
            while (size--) {
                auto node = q.front(); q.pop();
                
                if (not size) // last node on this level
                    view.push_back(node->val);
                
                // push children, next level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return view;
    }
};