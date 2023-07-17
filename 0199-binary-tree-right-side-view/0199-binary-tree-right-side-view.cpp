class Solution {
public:
    using tn = TreeNode;

    vector<int> rightSideView(TreeNode* root) {
        vector<int> view = {};
        if (!root) return view;
        queue<tn*> q;
        q.push(root);
        while (!q.empty()) {
            int z = q.size();
            for (int i = 0; i < z; ++i) {
                tn* curr = q.front();
                q.pop();
                if (i == z - 1) view.push_back(curr->val);
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
        return view;
    }
};