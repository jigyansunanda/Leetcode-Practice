using tn = TreeNode;

class Solution {
public:
    map<tn*, int> dp[2][2];

    int minCameraCover(TreeNode* root) {
        int ans = min(solve(root, 0, 0), solve(root, 1, 1));
        return ans;
    }

    int solve(tn* u, int is_camera_placed, int is_monitored) {
        if (dp[is_camera_placed][is_monitored].find(u) != dp[is_camera_placed][is_monitored].end()) return dp[is_camera_placed][is_monitored][u];
        int& ans = dp[is_camera_placed][is_monitored][u] = 0;
        if (is_camera_placed) {
            ans = 1;
            if (u->left) ans += min(solve(u->left, 0, 1), solve(u->left, 1, 1));
            if (u->right) ans += min(solve(u->right, 0, 1), solve(u->right, 1, 1));
            return ans;
        } else {
            vector<tn*> children;
            if (u->left) children.push_back(u->left);
            if (u->right) children.push_back(u->right);
            if (children.empty()) return ans = 1 - is_monitored;
            tn* c1 = children.front();
            tn* c2 = children.back();
            if (is_monitored) {
                ans = 0;
                if (u->left) ans += min(solve(u->left, 0, 0), solve(u->left, 1, 1));
                if (u->right) ans += min(solve(u->right, 0, 0), solve(u->right, 1, 1));
            } else {
                if (((int) children.size()) == 1) {
                    ans = solve(c1, 1, 1);
                } else {
                    ans = min(solve(c1, 1, 1) + min(solve(c2, 1, 1), solve(c2, 0, 0)), solve(c2, 1, 1) + min(solve(c1, 1, 1), solve(c1, 0, 0)));
                }
            }
            return ans;
        }
    }
};