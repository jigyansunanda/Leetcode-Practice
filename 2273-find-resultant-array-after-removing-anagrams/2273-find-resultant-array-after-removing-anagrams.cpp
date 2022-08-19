class Solution {
public:
	vector<string> removeAnagrams(vector<string>& words) {
		vector<string> v;
		v.push_back(words[0]);
		function<bool(string, string)> isAnagram = [&](string A, string B) {
			int c[26] = {0};
			for (auto &ch : A) c[ch - 'a']++;
			for (auto &ch : B) c[ch - 'a']--;
			for (int j = 0; j < 26; ++j) {
				if (c[j] != 0) return false;
			}
			return true;
		};
		for (int i = 1; i < words.size(); ++i) {
			if (isAnagram(v.back(), words[i])) continue;
			else v.push_back(words[i]);
		}
		return v;
	}
};