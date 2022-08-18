class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        int chars[26] = {0};
        for (auto c: allowed) chars[c-'a']++;
        for (auto &word: words) {
            bool isConsistent = true;
            for (auto &c: word) {
                if (chars[c-'a'] == 0) {
                    isConsistent = false;
                    break;
                }
            }
            ans += (isConsistent);
        }
        return ans;
    }
};