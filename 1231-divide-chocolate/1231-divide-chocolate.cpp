class Solution {
private:
    bool isPossible(vector<int>& sweetness, int k, int x) {
        int count = 0, sum = 0;
        for (int i = 0; i < (int)sweetness.size(); ++i) {
            sum += sweetness[i];
            if (sum < x) continue;
            else {
                count++;
                sum = 0;
            }
        }
        return (count >= k + 1);
    }

public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int n = sweetness.size();
        if (k == 0) return accumulate(sweetness.begin(), sweetness.end(), 0);
        if (k == n - 1) return *min_element(sweetness.begin(), sweetness.end());
        int lo = 0, hi = 1e9 + 1;
        while (hi > lo + 1) {
            int mid = lo + (hi - lo) / 2;
            if (isPossible(sweetness, k, mid)) lo = mid;
            else hi = mid;
        }
        return lo;
    }
};