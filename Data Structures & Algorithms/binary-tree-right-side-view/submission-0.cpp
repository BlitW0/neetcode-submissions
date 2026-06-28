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
        if (!root) 
            return vector <int> ();

        vector <int> ans;
        queue <pair<TreeNode*, int> > bfs;
        bfs.push({root, 0});

        while (!bfs.empty()) {
            auto p = bfs.front();
            TreeNode* node = p.first; int lvl = p.second;
            bfs.pop();

            // Keep overwriting the last seen value on level lvl
            if (ans.size() < lvl + 1)
                ans.push_back(node->val);
            else
                ans[lvl] = node->val;
            
            if (node->left) bfs.push({node->left, lvl + 1});
            if (node->right) bfs.push({node->right, lvl + 1});
        }

        return ans;
    }
};