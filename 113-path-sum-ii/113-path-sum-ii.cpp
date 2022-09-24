class Solution {
public:
    using str = string;
    using ll = long long;
    using ld = long double;
    using vi = vector<int>;
    using pii = pair<int, int>;
    using vvi = vector<vector<int>>;
    template <class T> using maxheap = priority_queue<T>;
    template <class T> using minheap = priority_queue<T, vector<T>, greater<T>>;

    Solution() {}
    ~Solution() {}

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> allPaths;
        vector<int> path;
        dfs(root, targetSum, allPaths, path);
        return allPaths;
    }

    void dfs(TreeNode* root, int sum, vector<vector<int>>& allPaths, vector<int> &path) {
        if (root == NULL) return;
        if (root->left == NULL and root->right == NULL) {
            if (sum == root->val) {
                path.push_back(root->val);
                allPaths.push_back(path);
                path.pop_back();
            }
            return;
        }
        path.push_back(root->val);
        dfs(root->left, sum - root->val, allPaths, path);
        dfs(root->right, sum - root->val, allPaths, path);
        path.pop_back();
    }
};