class Solution {
public:
    vector<int> ans;
    map<TreeNode*, TreeNode*> parent;
    set<TreeNode*> visit;

    void dfs(TreeNode* node) {
        if (!node ) return;
        if ( node->left ) {
            parent[node->left] = node;
            dfs(node->left);
        }
        if ( node->right) {
            parent[node->right] = node;
            dfs(node->right);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if (!root) return {};
        dfs(root);
        solve(target, K);
        return ans;
    }
    void solve( TreeNode* node, int K) {
        if (visit.find(node) != visit.end()) return;
        visit.insert(node);
        if ( K == 0 ) {
            ans.push_back(node->val);
            return;
        }
        if ( node->left ) {
            solve(node->left, K - 1);
        }
        if ( node->right) {
            solve(node->right, K - 1);
        }
        TreeNode* p = parent[node];
        if (p) solve(p, K - 1);
    }
};