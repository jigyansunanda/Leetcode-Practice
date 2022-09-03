class Solution {
public:
	int ans;

	int longestConsecutive(TreeNode* root) {
		ans = 0;
		if (root == NULL) return 0;
		solve(root, 1);
		return ans;
	}

	void solve(TreeNode* root, int c) {
		if (!root) return;
		ans = max(ans, c);
		if (root->left) {
			if (root->left->val == root->val + 1) solve(root->left, c + 1);
			else solve(root->left, 1);
		}
		if (root->right) {
			if (root->right->val == root->val + 1) solve(root->right, c + 1);
			else solve(root->right, 1);
		}
	}
};