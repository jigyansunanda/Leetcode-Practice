class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i <= n - 1; ++i) pre[i] = pre[i - 1] + nums[i];
        int ans = n + 1;
        deque<int> dq;
        for (int i = 0; i < n; ++i) {
            if (pre[i] >= k) ans = min(ans, i + 1);
            while (!dq.empty() and pre[i] <= pre[dq.back()]) dq.pop_back();
            while (!dq.empty() and pre[i] - pre[dq.front()] >= k) {
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }
            dq.push_back(i);
        }
        return (ans < n + 1) ? ans : -1;
    }
};