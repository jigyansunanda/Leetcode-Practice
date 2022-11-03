/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int answer;

    int maxPathSum(TreeNode* root) {
        answer = INT_MIN;
        dfs(root);
        return answer;
    }

    int dfs(TreeNode* root) {
        if (root == NULL) return 0;
        int left = (root->left == NULL) ? 0 : dfs(root->left);
        int right = (root->right == NULL) ? 0 : dfs(root->right);
        int maxPathSumAtNode = max({root->val, root->val + left, root->val + right, root->val + left + right});
        answer = max(answer, maxPathSumAtNode);
        return max({root->val, root->val + left, root->val + right, 0});
    }
};