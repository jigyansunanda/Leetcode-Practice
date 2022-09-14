class Solution {
public:
	vector<int> count;
	int ans;

	int pseudoPalindromicPaths (TreeNode* root) {
		count.assign(10, 0);
		ans = 0;
		dfs(root);
		return ans;
	}

	bool isPalindrome() {
		int rem = 0;
		for (auto &e : count) {
			rem += (e % 2);
		}
		return (rem <= 1);
	}

	void dfs(TreeNode* root) {
		if (root == NULL) return;
		if (root->left == NULL and root->right == NULL) {
			count[root->val]++;
			if (isPalindrome()) ++ans;
			count[root->val]--;
			return;
		}
		count[root->val]++;
		if (root->left) dfs(root->left);
		if (root->right) dfs(root->right);
		count[root->val]--;
	}
};