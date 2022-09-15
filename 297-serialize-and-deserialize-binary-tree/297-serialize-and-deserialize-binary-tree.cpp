class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root, string& ans) {
		if (!root) {
			ans += "#,";
		} else {
			ans += to_string(root->val) + ",";
			serialize(root->left, ans);
			serialize(root->right, ans);
		}
		return ans;
	}

	string serialize(TreeNode* root) {
		string ans = "";
		return serialize(root, ans);
		return ans;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		queue<string> q;
		string tmp = "";
		for (auto &c : data) {
			if (c == ',') {
				q.push(tmp);
				tmp = "";
			} else tmp += c;
		}
		return makeTree(q);
	}

	TreeNode* makeTree(queue<string> &q) {
		if (q.empty()) return NULL;
		string val = q.front();
		q.pop();
		if (val == "#") return NULL;
		TreeNode* root = new TreeNode(stoi(val));
		root->left = makeTree(q);
		root->right = makeTree(q);
		return root;
	}
};