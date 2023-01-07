class Solution {
public:
    int minimumPartition(string s, int k) {
        int index = 0, count = 0;
        int n = s.size();
        long long curr = 0;
        while (index < n) {
            int previndex = index;
            while (index < n) {
                if ((curr * 10LL) + (s[index] - '0') > (long long)k) {
                    break;
                } else {
                    curr = (curr * 10LL) + (s[index] - '0');
                    ++index;
                }
            }
            if (index == previndex) return -1;
            else {count++; curr = 0LL;}
        }
        return count;
    }
};