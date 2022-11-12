class Solution {
private:
    bool isGreater(string A, string B) {
        if (A.size() > B.size()) return true;
        else if (A.size() < B.size()) return false;
        else {
            for (int i = 0; i < (int)A.size(); ++i) {
                if (A[i] > B[i]) return true;
                else if (A[i] < B[i]) return false;
            }
            return false;
        }
    }
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        auto comp = [&](const pair<string, int>& a, const pair<string, int>& b) {
            return isGreater(a.first, b.first);
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> pq(comp);
        for (int i = 0; i < (int)nums.size(); ++i) {
            pair p = make_pair(nums[i], i);
            pq.push(p);
            if ((int)pq.size() > k) pq.pop();
        }
        return pq.top().first;
    }
};