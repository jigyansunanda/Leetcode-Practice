class Solution {
public:
    int hIndex(vector<int>& citations) {
        int count[1001] = {0};
        for (auto &c : citations) count[c]++;
        for (int i = 999; i >= 0; --i) count[i] += count[i + 1];
        for (int i = 1000; i >= 0; --i) if (count[i] >= i) return i;
        return 0;
    }
};