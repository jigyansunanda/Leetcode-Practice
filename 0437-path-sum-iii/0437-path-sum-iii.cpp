class Solution {
public:
    int ans;

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        ans = 0;
        dfs(root, targetSum);
        return ans;
    }

    void dfs(TreeNode* root, int targetSum) {
        if (root) {
            check(root, targetSum, root->val);
            dfs(root->left, targetSum);
            dfs(root->right, targetSum);
        }
    }

    void check(TreeNode* root, int targetSum, long long sum) {
        if (root == NULL) return;
        if ((long long) targetSum == sum) ans++;
        if (root->left) check(root->left, targetSum, sum + root->left->val);
        if (root->right) check(root->right, targetSum, sum + root->right->val);
    }
};