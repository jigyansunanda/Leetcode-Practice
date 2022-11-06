class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        const long long mod = 1e9 + 7;
        long long endingAtZero = 0, endingAtOne = 0;
        for (auto &c : binary) {
            if (c == '0') endingAtZero = (endingAtZero + endingAtOne) % mod;
            else endingAtOne = (endingAtZero + endingAtOne + 1) % mod;
        }
        return (endingAtZero + endingAtOne + (endingAtZero or (binary[0] == '0'))) % mod;
    }
};