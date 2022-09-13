class Solution {
public:
	map<TreeNode*, int> dp1, dp2;

	int rob(TreeNode* root) {
		dfs(root);
		return max(dp1[root], dp2[root]);
	}

	void dfs(TreeNode* root) {
		if (!root) return;
		if (dp1.find(root) != dp1.end()) return;
		dp1[root] = root->val;
		dp2[root] = 0;
		dfs(root->left);
		dfs(root->right);
		if (root->left) {
			dp1[root] += dp2[root->left];
			dp2[root] += max(dp1[root->left], dp2[root->left]);
		}
		if (root->right) {
			dp1[root] += dp2[root->right];
			dp2[root] += max(dp1[root->right], dp2[root->right]);
		}
	}
};