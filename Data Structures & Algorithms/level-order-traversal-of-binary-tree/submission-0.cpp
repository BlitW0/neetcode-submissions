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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return vector <vector <int> > ();
        }

        vector <vector <int> > ans;
        queue <pair<TreeNode*, int> > bfs;
        bfs.push({root, 0});

        while (!bfs.empty()) {
            auto p = bfs.front();
            int lvl = p.second; TreeNode* node = p.first;
            bfs.pop();

            if (ans.size() < lvl + 1) {
                ans.push_back(vector <int> ());
            }
            ans[lvl].push_back(node->val);

            if (node->left) bfs.push({node->left, lvl + 1});
            if (node->right) bfs.push({node->right, lvl + 1});
        }

        return ans;
    }
};