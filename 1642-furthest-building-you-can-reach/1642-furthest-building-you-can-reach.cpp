class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        vector<int> diff;
        for (int i = 1; i <= n - 1; ++i) diff.push_back(max(0, heights[i] - heights[i - 1]));
        int lo = 0, hi = n;
        while (hi > lo + 1) {
            int mid = (lo + hi) >> 1;
            if (isReachable(heights, bricks, ladders, mid)) lo = mid;
            else hi = mid;
        }
        return lo;
    }

    bool isReachable(vector<int>& heights, int bricks, int ladders, int index) {
        vector<int> diff;
        for (int i = 1; i <= index; ++i) {
            if (heights[i] > heights[i - 1]) diff.push_back(heights[i] - heights[i - 1]);
        }
        sort(diff.begin(), diff.end(), greater<int>());
        for (int i = ladders; i <= ((int) diff.size()) - 1; ++i) {
            if (bricks < diff[i]) return false;
            bricks -= diff[i];
        }
        return true;
    }
};