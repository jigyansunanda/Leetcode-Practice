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
    map<Node*, Node*> vis;

    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        vector<Node*> neighbors;
        Node* root = new Node(node->val, neighbors);
        vis[node] = root;
        for (Node* child : node->neighbors) {
            if (vis.find(child) == vis.end()) {
                root->neighbors.push_back(cloneGraph(child));
            } else {
                root->neighbors.push_back(vis[child]);
            }
        }
        return root;
    }
};