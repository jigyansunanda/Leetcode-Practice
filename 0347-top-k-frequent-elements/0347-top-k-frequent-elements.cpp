class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if ((int)nums.size() == k) return nums;
        unordered_map<int, int> mp;
        for (auto &num : nums) mp[num] += 1;
        auto comp = [&mp](int a, int b) {return mp[a] > mp[b];};
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        for (auto &p : mp) {
            pq.push(p.first);
            if ((int)pq.size() > k) pq.pop();
        }
        vector<int> ans(k);
        for (int i = k - 1; i >= 0; --i) {
            ans[i] = pq.top();
            pq.pop();
        }
        return ans;
    }
};