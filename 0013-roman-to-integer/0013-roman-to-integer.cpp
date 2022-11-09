class Solution {
public:
    unordered_map<char, int> values = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int romanToInt(string s) {
        int index = 0, ans = 0;
        while (index < (int)s.size()) {
            if (index + 1 < (int)s.size() and values[s[index]] < values[s[index + 1]]) {
                ans += values[s[index + 1]] - values[s[index]];
                index += 2;
            } else {
                ans += values[s[index]];
                index += 1;
            }
        }
        return ans;
    }
};