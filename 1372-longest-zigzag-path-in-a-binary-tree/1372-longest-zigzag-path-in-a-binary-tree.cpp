class Solution {
public:
	int longestZigZag(TreeNode* root) {
		auto res = dfs(root);
		return res[2];
	}

	vector<int> dfs(TreeNode* root) {
		if (!root) return { -1, -1, -1};
		auto left = dfs(root->left);
		auto right = dfs(root->right);
		int maxLengthInSubTree = max({left[2], right[2], max(left[1], right[0]) + 1});
		return {left[1] + 1, right[0] + 1, maxLengthInSubTree};
	}
};