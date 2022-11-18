class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        vector<int> cnt(101), ans;
        for (auto &arr : arrays)
            for (int n : arr)
                if (++cnt[n] == arrays.size())
                    ans.push_back(n);
        return ans;
    }
};