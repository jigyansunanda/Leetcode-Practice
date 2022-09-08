class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		// inorder = left -> root -> right
		vector<int> ans;
		stack<TreeNode*> st;
		while (!st.empty() or root != NULL) {
			while (root != NULL) {
				st.push(root);
				root = root->left;
			}
			if (!st.empty()) {
				root = st.top(); st.pop();
				ans.push_back(root->val);
				root = root->right;
			}
		}
		return ans;
	}
};