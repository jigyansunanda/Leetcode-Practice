class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto comp = [&](const pair<int, int>& a, const pair<int, int>& b) {
            return (a.first > b.first);
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        for (int i = 0; i < (int)nums.size(); ++i) {
            pq.push(make_pair(nums[i], i));
            if ((int)pq.size() > k) pq.pop();
        }
        return pq.top().first;
    }
};