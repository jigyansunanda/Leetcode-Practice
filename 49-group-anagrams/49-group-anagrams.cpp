class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> ans;
		map<string, vector<string>> mp;
		function<string(string)> sorted = [](string x) {
			int c[26] = {0};
			for (auto &ch : x) c[ch - 'a']++;
			string res = "";
			for (int i = 0; i < 26; ++i) {
				res += string(c[i], 'a' + i);
			}
			return res;
		};
		for (string s : strs) {
			mp[sorted(s)].push_back(s);
		}
		for (auto &p : mp) {
			ans.push_back(p.second);
		}
		return ans;
	}
};