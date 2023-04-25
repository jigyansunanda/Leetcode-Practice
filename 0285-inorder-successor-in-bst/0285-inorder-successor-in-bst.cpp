/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

typedef TreeNode tn;

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root or !p) return NULL;
        stack<tn*> st;
        while (!st.empty() or root) {
            // cout << "Entered\n";
            while (root) {
                st.push(root);
                root = root->left;
            }
            if (st.empty()) continue;
            root = st.top();
            st.pop();
            // cout << root->val << '\n';
            if (root->val > p->val) return root;
            root = root->right;
        }        
        return NULL;
    }
};