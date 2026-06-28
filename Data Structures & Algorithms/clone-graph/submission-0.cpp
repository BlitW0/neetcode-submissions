/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map <Node*, Node*> cnode;

    Node* cloneGraph(Node* node) {
        if (!node) // Empty graph
            return node;
        // Node hasn't been cloned before
        if (cnode.find(node) == cnode.end()) {
            cnode[node] = new Node(node->val, {});
            for (auto nei : node->neighbors)
                cnode[node]->neighbors.push_back(cloneGraph(nei));
        }
        return cnode[node];
    }
};