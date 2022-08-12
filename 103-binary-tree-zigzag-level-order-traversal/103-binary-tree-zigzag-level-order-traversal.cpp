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
    using tn = TreeNode;

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        deque<tn*> dq;
        dq.push_back(root);
        int iter = 0;
        while (!dq.empty()) {
            vector<int> subans;
            for (int sz = dq.size(); sz > 0; --sz) {
                if (iter % 2 == 0) {
                    tn* node = dq.back();
                    dq.pop_back();
                    subans.push_back(node->val);
                    if (node->left) dq.push_front(node->left);
                    if (node->right) dq.push_front(node->right);
                } else {
                    tn* node = dq.front();
                    dq.pop_front();
                    subans.push_back(node->val);
                    if (node->right) dq.push_back(node->right);
                    if (node->left) dq.push_back(node->left);
                }
            }
            ans.push_back(subans);
            ++iter;
        }
        return ans;
    }
};