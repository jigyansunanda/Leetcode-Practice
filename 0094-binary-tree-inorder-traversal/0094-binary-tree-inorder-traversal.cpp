typedef TreeNode tn;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // inorder: left -> root -> right
        if (!root) return {};
        stack<tn*> st;
        vector<int> ans;
        while (!st.empty() or root) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            if (st.empty()) break;
            root = st.top();
            st.pop();
            ans.push_back(root->val);
            root = root->right;
        }
        return ans;
    }
};