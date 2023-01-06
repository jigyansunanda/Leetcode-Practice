class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        sort(costs.begin(), costs.end());
        int index = 0, ans = 0;
        while (index < n and costs[index] <= coins) {
            coins -= costs[index];
            ++ans;
            ++index;
        }
        return ans;
    }
};