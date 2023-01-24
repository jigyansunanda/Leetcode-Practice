class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        set<int> st1(nums1.begin(), nums1.end());
        for (auto e : nums2) {
            if (st1.find(e) != st1.end()) return e;
        }
        return -1;
    }
};