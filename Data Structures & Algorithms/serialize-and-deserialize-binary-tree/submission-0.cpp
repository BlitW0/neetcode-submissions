/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        if (not root) return s;

        queue <TreeNode*> q;
        q.push(root);
        while (not q.empty()) {
            auto cur = q.front(); q.pop();
            s.append( cur ? to_string(cur->val) : "#" ); // # for null
            s.append(","); // delimiter
            if (cur) q.push(cur->left), q.push(cur->right);
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode *root = nullptr;
        if (data.empty()) return root;
        
        stringstream s(data);
        string str;
        getline(s, str, ',');

        root = new TreeNode( stoi(str) );
        queue <TreeNode*> q;
        q.push(root);
        while (not q.empty()) {
            auto cur = q.front(); q.pop();
            // next str is left child
            getline(s, str, ',');
            if (str != "#") cur->left = new TreeNode( stoi(str) );
            // next str is right child
            getline(s, str, ',');
            if (str != "#") cur->right = new TreeNode( stoi(str) );
            
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));