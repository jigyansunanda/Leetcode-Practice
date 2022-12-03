class Solution {
 public:
  vector<int> frequencySort(vector<int>& nums) {
    vector<int> count(201, 0);
    for (auto& num : nums) count[num + 100]++;
    vector<pair<int, int>> v;
    for (int i = 0; i < 201; ++i) {
      if (count[i]) {
        v.emplace_back(count[i], i - 100);
      }
    }
    sort(v.begin(), v.end(), [&](const auto& A, const auto& B) {
      if (A.first != B.first)
        return A.first < B.first;
      else
        return A.second > B.second;
    });
    int index = 0;
    for (auto& p : v) {
      for (int j = 0; j < p.first; j++) {
        nums[index++] = p.second;
      }
    }
    return nums;
  }
};