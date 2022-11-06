class Solution {
public:
    int n;
    vector<vector<int>> tree;

    int componentValue(vector<int>& nums, vector<vector<int>>& edges, int ans = 0) {
        n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        tree.resize(n);
        for (auto &e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }
        for (int i = 1; i * i <= sum; ++i) {
            if (sum % i == 0) {
                int compValue = (sum / i);
                int compCount = i;
                dfs(0, 0, nums, compValue, compCount);
                if (compCount == 0) ans = max(ans, i - 1);
                if (sum / i != i) {
                    compValue = i;
                    compCount = (sum / i);
                    dfs(0, 0, nums, compValue, compCount);
                    if (compCount == 0) ans = max(ans, (sum / i) - 1);
                }
            }
        }
        return ans;
    }

    int dfs(int u, int p, vector<int>& nums, int compValue, int& compCount) {
        int sum = nums[u];
        for (int v : tree[u]) {
            if (v != p) {
                sum += dfs(v, u, nums, compValue, compCount);
            }
        }
        if (sum == compValue) {
            --compCount;
            return 0;
        }
        return sum;
    }
};