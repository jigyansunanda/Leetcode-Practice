class Solution {
public:
    int maximum69Number (int num) {
        vector<int> d;
        while (num) {
            d.push_back(num % 10);
            num /= 10;
        }
        reverse(d.begin(), d.end());
        for (int i = 0; i < d.size(); ++i) {
            if (d[i] == 6) {
                d[i] = 9;
                break;
            }
        }
        int ans = 0;
        for (int i = 0; i < d.size(); ++i) {
            ans = (ans * 10) + d[i];
        }
        return ans;
    }
};