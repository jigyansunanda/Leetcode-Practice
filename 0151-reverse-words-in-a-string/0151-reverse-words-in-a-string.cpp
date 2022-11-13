class Solution {
public:
    string reverseWords(string s) {
        while (s.empty() == false and s.back() == ' ') s.pop_back();
        reverse(s.begin(), s.end());
        while (s.empty() == false and s.back() == ' ') s.pop_back();
        int index = 0, start = 0;
        while (index < (int) s.size()) {
            start = index;
            if (s[index] == ' ') {++index; continue;}
            while (index < (int) s.size() and s[index] != ' ') index++;
            reverse(s.begin() + start, s.begin() + index);
        }
        index = 0;
        int curr = 0;
        while (curr < (int)s.size()) {
            if (s[curr] == ' ' and s[index - 1] == ' ') {++curr; continue;}
            else {
                swap(s[curr], s[index]);
                ++curr; ++index;
            }
        }
        return s.substr(0, index);
    }
};