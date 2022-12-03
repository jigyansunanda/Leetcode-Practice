class Solution {
 public:
  string frequencySort(string s) {
    int cnt[128] = {0};
    for (auto& c : s) cnt[c]++;
    vector<pair<char, int>> v;
    for (int i = 0; i < 128; ++i) {
      if (cnt[i]) {
        char ch = (char)(i);
        v.emplace_back(ch, cnt[i]);
      }
    }
    sort(v.begin(), v.end(),
         [&](const auto& A, const auto& B) { return (A.second > B.second); });
    string ans = "";
    for (auto& p : v) {
      for (int j = 0; j < p.second; ++j) {
        ans.push_back(p.first);
      }
    }
    return ans;
  }
};