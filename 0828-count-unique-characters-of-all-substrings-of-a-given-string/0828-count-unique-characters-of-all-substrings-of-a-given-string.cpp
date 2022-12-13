class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size(), ans = 0;
        int lastTwoOcc[26][2];
        memset(lastTwoOcc, -1, sizeof(int) * 52);
        for (int i = 0; i < n; ++i) {
            int index = s[i] - 'A';
            ans += (i - lastTwoOcc[index][1]) * (lastTwoOcc[index][1] - lastTwoOcc[index][0]);
            lastTwoOcc[index][0] = lastTwoOcc[index][1];
            lastTwoOcc[index][1] = i;
        }
        for (int index = 0; index < 26; ++index) {
            ans += (n - lastTwoOcc[index][1]) * (lastTwoOcc[index][1] - lastTwoOcc[index][0]);
        }
        return ans;
    }
};