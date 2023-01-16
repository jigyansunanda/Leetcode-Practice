class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size(), index = 0;
        vector<vector<int>> ans;
        while (index < n and intervals[index][1] < newInterval[0]) ans.push_back(intervals[index++]);
        while (index < n and intervals[index][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[index][0]);
            newInterval[1] = max(newInterval[1], intervals[index][1]);
            ++index;
        }
        ans.push_back(newInterval);
        while (index < n) ans.push_back(intervals[index++]);
        return ans;
    }
};