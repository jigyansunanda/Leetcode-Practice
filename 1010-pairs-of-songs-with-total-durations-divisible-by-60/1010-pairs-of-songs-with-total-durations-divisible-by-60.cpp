class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time, int ans = 0) {
        int cnt[60] = {0};
        for (int c : time) {
            if (c % 60 == 0) ans += cnt[0];
            else ans += cnt[60 - (c % 60)];
            cnt[c % 60]++;
        }
        return ans;
    }
};