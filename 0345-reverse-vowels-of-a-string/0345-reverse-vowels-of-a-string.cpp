class Solution {
public:
    bool isvowel(char c) {
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
    string reverseVowels(string s) {
        int l = 0, r = s.size()-1;
        while (l < r) {
            while (!isvowel(tolower(s[l]))) {
                l++;
                if (l==s.size()) return s;
            }
            while (!isvowel(tolower(s[r]))) {
                r--;
                if (r<0) return s;
            }
            if (l >= r) return s;
            swap(s[l], s[r]);
            l++;
            r--;
            
        }
        return s;
    }
};