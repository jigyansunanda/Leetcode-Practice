class Solution {
private:
    vector<int> get(string& s, int index) {
        vector<int> ans = {0, 0};
        int l = index, r = index;
        while (l >= 0 and r < ((int) s.size())) {
            if (s[l] == s[r]) {
                --l;
                ++r;
            } else break;
        }
        ++l;
        --r;
        if (r - l + 1 > ans[0]) {
            ans[0] = r - l + 1;
            ans[1] = l;
        }
        l = index, r = index + 1;
        while (l >= 0 and r < ((int) s.size())) {
            if (s[l] == s[r]) {
                --l;
                ++r;
            } else break;
        }
        ++l;
        --r;
        if (r - l + 1 > ans[0]) {
            ans[0] = r - l + 1;
            ans[1] = l;
        }
        return ans;
    }

public:
    string longestPalindrome(string s, int maxLength = 0, int startIndex = -1) {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            auto v = get(s, i);
            if (v[0] > maxLength) {
                maxLength = v[0];
                startIndex = v[1];
            }
        }
        return s.substr(startIndex, maxLength);
    }
};