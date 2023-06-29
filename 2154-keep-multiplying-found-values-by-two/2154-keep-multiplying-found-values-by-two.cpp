class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int> st(nums.begin(), nums.end());
        while (true) {
            auto it = st.find(original);
            if (it == st.end()) break;
            st.erase(it);
            original *= 2;
        }
        return original;
    }
};