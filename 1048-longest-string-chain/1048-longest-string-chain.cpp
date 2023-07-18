class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [&](const auto& A, const auto& B) { return ((int) A.size()) < ((int) B.size()); });
        unordered_map<string, int> dp;
        int maxLength = 0;
        for (auto& word : words) {
            int currLength = 1;
            for (int i = 0; i < ((int) word.size()); ++i) {
                string s = word.substr(0, i) + word.substr(i + 1);
                if (dp.find(s) != dp.end()) {
                    currLength = max(currLength, dp[s] + 1);
                }
            }
            dp[word] = currLength;
            maxLength = max(maxLength, currLength);
        }
        return maxLength;
    }
};