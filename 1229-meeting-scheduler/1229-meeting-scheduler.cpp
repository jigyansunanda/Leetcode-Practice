class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        int a = 0, b = 0;
        while (a < slots1.size() and b < slots2.size()) {
            int startTime = max(slots1[a][0], slots2[b][0]);
            int endTime = min(slots1[a][1], slots2[b][1]);
            if (endTime - startTime >= duration) {
                return {startTime, startTime + duration};
            }
            if (slots1[a][1] < slots2[b][1]) {
                a++;
            } else {
                b++;
            }
        }
        return {};
    }
};