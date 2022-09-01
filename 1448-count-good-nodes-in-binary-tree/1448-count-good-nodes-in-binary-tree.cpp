using tn = TreeNode;

class Solution {
public:
	int goodNodes(TreeNode* root, int maxTillNow = INT_MIN) {
		if (root == NULL) return 0;
		int ans = (root->val < maxTillNow) ? 0 : 1;
		maxTillNow = max(maxTillNow, root->val);
		ans += goodNodes(root->left, maxTillNow);
		ans += goodNodes(root->right, maxTillNow);
		return ans;
	}
};