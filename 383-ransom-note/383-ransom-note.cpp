class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int c[26] = {0};
        for (auto ch: magazine) c[ch-'a']++;
        for (auto ch: ransomNote) c[ch-'a']--;
        for (int i=0; i<26; ++i) {
            if (c[i] < 0) return false;
        }
        return true;
    }
};