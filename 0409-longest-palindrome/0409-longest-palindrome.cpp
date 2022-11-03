class Solution {
public:
    int longestPalindrome(string s) {
        int c[128] = {0};
        for (auto &ch : s) c[ch]++;
        int ans = 0;
        vector<int> odd;
        for (int i = 0; i < 128; ++i) {
            if (c[i] % 2 == 0) ans += c[i];
            else odd.push_back(c[i]);
        }
        sort(odd.begin(), odd.end());
        if (odd.empty() == false) {
            ans += odd.back();
            odd.pop_back();
        }
        ans += accumulate(odd.begin(), odd.end(), 0);
        ans -= odd.size();
        return ans;
    }
};