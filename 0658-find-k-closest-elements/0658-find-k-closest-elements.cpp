class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = ((int) arr.size());
        int l = 0, r = n - 1;
        while (r - l > 1) {
            int mid = (r + l) >> 1;
            if (arr[mid] <= x) l = mid;
            else r = mid;
        }
        if (abs(x - arr[l]) <= abs(x - arr[r])) r = l;
        else l = r;
        while (r - l + 1 < k) {
            if (l == 0) {
                ++r;
            } else if (r == n - 1) {
                --l;
            } else {
                if (abs(x - arr[l - 1]) <= abs(x - arr[r + 1])) --l;
                else ++r;
            }
        }
        vector<int> ans;
        for (int i = l; i <= r; ++i) {
            ans.push_back(arr[i]);
        }
        return ans;
    }
};