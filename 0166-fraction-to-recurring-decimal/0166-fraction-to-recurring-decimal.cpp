class Solution {
public:
    string fractionToDecimal(int n, int d) {
        string ans = "";
        if ((n < 0 && d > 0) || (n > 0 && d < 0)) ans += '-';
        long long a = abs(n);
        long long b = abs(d);
        long long num = abs(a / b);
        ans += to_string(num);
        long long rem = abs(a % b);
        if (rem == 0) return ans;
        ans.push_back('.');
        string dec = "";
        unordered_map<int, int> mp;
        while (rem) {
            if (mp.find(rem) != mp.end()) {
                int index = mp[rem];
                string recurring = dec.substr(index);
                dec.erase(index);
                dec += '(' + recurring + ')';
                break;
            } else {
                mp[rem] = dec.size();
                dec += to_string(rem * 10 / b);
                rem = (rem * 10) % b;
            }
        }
        ans += dec;
        return ans;
    }
};