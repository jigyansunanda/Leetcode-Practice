class Solution {
public:
    using tn = TreeNode;

    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        stack<tn*> st;
        st.push(root);
        tn* curr = root;
        while (!st.empty()) {
            while (curr) {
                ans.push_back(curr->val);
                if (curr->right) st.push(curr->right);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
        }
        return ans;
    }
};