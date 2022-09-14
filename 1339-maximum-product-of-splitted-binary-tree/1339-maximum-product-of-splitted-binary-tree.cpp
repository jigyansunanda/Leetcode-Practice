class Solution {
public:
	long long mod = 1e9 + 7;
	long long totalsum, ans;


    int maxProduct(TreeNode* root) {
    	totalsum = 0, ans = 0;

    	function<void(TreeNode*)> dfs1 = [&](TreeNode* root) {
    		if (!root) return;
    		totalsum += root->val;
    		dfs1(root->left); dfs1(root->right);
    	};
    	dfs1(root);

    	dfs2(root);
    	return ans%mod;
    }

    long long dfs2(TreeNode* root) {
    	if (!root) return 0;
    	long long sumFromLeaf = dfs2(root->left) + dfs2(root->right);
    	sumFromLeaf += root->val;
    	ans = max(ans, sumFromLeaf * (totalsum - sumFromLeaf));
    	return sumFromLeaf;
    }
};