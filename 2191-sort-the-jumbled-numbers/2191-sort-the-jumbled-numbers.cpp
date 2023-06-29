class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        auto get = [&](int x) -> int {
            if (x == 0) return mapping[0];
            else {
                vector<int> digits = {};
                while (x) {
                    digits.push_back(mapping[x % 10]);
                    x /= 10;
                }
                int num = 0;
                while (!digits.empty()) {
                    num = (num * 10) + digits.back();
                    digits.pop_back();
                }
                return num;
            }
        };

        unordered_map<int, int> mappedValue;
        for (auto& e : nums) mappedValue[e] = get(e);
        sort(nums.begin(), nums.end(), [&](const auto& A, const auto& B) { return mappedValue[A] < mappedValue[B]; });
        return nums;
    }
};