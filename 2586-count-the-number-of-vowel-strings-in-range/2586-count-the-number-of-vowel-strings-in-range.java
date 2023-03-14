class Solution {
    public boolean is_vowel(char c) {
        return (c == 'a' || c == 'e' || c== 'i'||c== 'o' ||c== 'u');
    }
    public int vowelStrings(String[] words, int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; ++i) {
            if (is_vowel(words[i].charAt(0)) && is_vowel(words[i].charAt(words[i].length() - 1))) {
                ++ans;
            }
        }
        return ans;
    }
}