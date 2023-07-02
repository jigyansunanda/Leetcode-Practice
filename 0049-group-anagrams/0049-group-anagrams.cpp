class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (auto& s : strs) mp[get(s)].push_back(s);
        vector<vector<string>> ans;
        for (auto& it : mp) ans.push_back(it.second);
        return ans;
    }

    string get(string& s) {
        int c[26] = {0};
        for (auto ch : s) c[ch - 'a']++;
        string ans = "";
        for (int i = 0; i < 26; ++i) ans += string(c[i], (char) ('a' + i));
        return ans;
    }
};