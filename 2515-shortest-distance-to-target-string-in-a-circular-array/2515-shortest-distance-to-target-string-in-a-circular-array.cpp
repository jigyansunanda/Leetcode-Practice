class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        unordered_set<string>  st(words.begin(), words.end());
        if (st.find(target) == st.end()) return -1;
        int ans = INT_MAX;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == target) {
                ans = min({abs(i - startIndex), (int)words.size() - abs(i - startIndex), ans});
            }
        }
        return ans;
    }
};