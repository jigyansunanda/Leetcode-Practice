class Solution {
public:
    vector<vector<int>> res;

    void permute(vector<int> num, int l, int r) {
        if (l == r) {
            res.push_back(num);
            return;
        }
        for (int k = l; k <= r; k++) {
            if (l != k && (num[l] == num[k] or num[k] == num[k - 1])) continue;
            swap(num[l], num[k]);
            permute(num, l + 1, r);
            // swap(num[l], num[k]);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        permute(num, 0, num.size() - 1);
        return res;
    }
};