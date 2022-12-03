class Solution {
 public:
  int firstUniqChar(string s) {
    vector<int> cnt(26, -1);
    for (int i = 0; i < s.size(); ++i) {
      if (cnt[s[i] - 'a'] == -2)
        continue;
      else if (cnt[s[i] - 'a'] == -1)
        cnt[s[i] - 'a'] = i;
      else
        cnt[s[i] - 'a'] = -2;
    }
    int ans = INT_MAX;
    for (int i = 0; i < 26; ++i) {
      if (cnt[i] >= 0) ans = min(ans, cnt[i]);
    }
    return (ans == INT_MAX) ? -1 : ans;
  }
};