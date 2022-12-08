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
    void get(TreeNode* root, vector<int>& v) {
        if (root == NULL) return;
        get(root->left, v);
        if (root->left == NULL and root->right == NULL) v.push_back(root->val);
        get(root->right, v);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> A, B;
        get(root1, A);
        get(root2, B);
        return (A == B);
    }
};