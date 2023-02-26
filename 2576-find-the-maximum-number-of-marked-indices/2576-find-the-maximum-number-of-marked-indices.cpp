#define nl         '\n'
#define fi         first
#define se         second
#define skip       continue
#define sz(x)      ((int) (x).size())
#define all(v)     (v).begin(), (v).end()
#define fill(a, k) memset(a, k, sizeof(a))

class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(all(nums));
        int n = sz(nums), ans = 0, lo = 0, hi = (n/2);
        while (lo < (n/2) and hi < n) {
            if (nums[lo]*2 <= nums[hi]) {
                ++lo; ++hi; ans+=2;
            }else ++hi;
        }
        return ans;
    }
};