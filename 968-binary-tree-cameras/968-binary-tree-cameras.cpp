class Solution {
public:
    unordered_map<TreeNode*, int> dp[2][2];

    int minCameraCover(TreeNode* root) {
        return solve(root, 0, 0);
    }

    // isMonitored means is the current node is already being monitored or not
    // isCameraPlced means whether now I am going to place a camera at it or not
    int solve(TreeNode* root, int isCameraPlaced, int isMonitored) {
        if (!root) return 0;
        if (dp[isCameraPlaced][isMonitored].find(root) != dp[isCameraPlaced][isMonitored].end()) {
            return dp[isCameraPlaced][isMonitored][root];
        }
        if (isCameraPlaced) {
            return dp[isCameraPlaced][isMonitored][root] = 1 + solve(root->left, 0, 1) + solve(root->right, 0, 1);
        }
        if (isMonitored) {
            int placeCamera = 1 + solve(root->left, 0, 1) + solve(root->right, 0, 1);
            int noCamera = solve(root->left, 0, 0) + solve(root->right, 0, 0);
            return dp[isCameraPlaced][isMonitored][root] = min(placeCamera, noCamera);
        }
        int placeCameraAtRoot = 1 + solve(root->left, 0, 1) + solve(root->right, 0, 1);
        int placeCameraAtLeft = (!root->left) ? INT_MAX : solve(root->left, 1, 0) + solve(root->right, 0, 0);
        int placeCameraAtRight = (!root->right) ? INT_MAX : solve(root->left, 0, 0) + solve(root->right, 1, 0);
        int ans = min({placeCameraAtRoot, placeCameraAtLeft, placeCameraAtRight});
        return dp[isCameraPlaced][isMonitored][root] = ans;
    }
};