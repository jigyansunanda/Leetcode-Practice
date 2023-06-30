class Codec {
private:
    string serialize(TreeNode* root, string& s) {
        if (root == NULL) {
            s += "$,";
        } else {
            s += to_string(root->val) + ",";
            serialize(root->left, s);
            serialize(root->right, s);
        }
        return s;
    }

    TreeNode* getTree(queue<string>& q) {
        if (q.empty()) return NULL;
        string val = q.front();
        q.pop();
        if (val == "$") return NULL;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = getTree(q);
        root->right = getTree(q);
        return root;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        return serialize(root, s);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string tmp = "";
        for (auto c : data) {
            if (c == ',') {
                q.push(tmp);
                tmp = "";
            } else {
                tmp += c;
            }
        }
        return getTree(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));