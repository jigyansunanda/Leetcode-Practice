class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        int n = arr.size();
        long long ans = 0;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            int j = i;
            vector<int> nums;
            while (!vis[j]) {
                vis[j] = true;
                nums.push_back(arr[j]);
                j = (j + k) % n;
            }
            if (nums.empty()) continue;
            int num = get(nums, ((int) nums.size()));
            for (auto& e : nums) ans += abs(e - num);
        }
        return ans;
    }

    int get(vector<int>& A, int z) {
        sort(A.begin(), A.end());
        if (z & 1) return A[z / 2];
        else return (A[z / 2] + A[(z / 2) - 1]) / 2;
    }
};