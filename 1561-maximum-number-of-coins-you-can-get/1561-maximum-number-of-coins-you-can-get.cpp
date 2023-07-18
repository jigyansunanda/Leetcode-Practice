class Solution {
public:
    int maxCoins(vector<int>& piles, int ans = 0) {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int i = 0, j = n - 1;
        while (i < j) {
            ans += piles[j - 1];
            i++;
            j -= 2;
        }
        return ans;
    }
};