/* ----------------------------------- Debugger ---------------------------------------- */

template<typename A, typename B> std::ostream& operator<<(std::ostream &os, const std::pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template < typename T_container, typename T = typename std::enable_if < !std::is_same<T_container, std::string>::value, typename T_container::value_type >::type > std::ostream & operator<<(std::ostream &os, const T_container &v) { os << '{'; std::string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void debug() { std::cout << '\n'; }
template<typename Head, typename... Tail> void debug(Head H, Tail... T) { std::cout << ' ' << H; debug(T...); }

#define debug(...) std::cout << "(" << #__VA_ARGS__ << "):", debug(__VA_ARGS__)

/* ------------------------------------------------------------------------------------- */

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> Palindromes, notPalindromes;
        for (auto &word : words) {
            if (word[0] == word[1]) {
                Palindromes[word]++;
            } else {
                notPalindromes[word]++;
            }
        }
        int length = 0;
        for (auto &it : notPalindromes) {
            string rev = ""; rev.push_back(it.first[1]); rev.push_back(it.first[0]);
            if (notPalindromes.find(it.first) != notPalindromes.end() and notPalindromes.find(rev) != notPalindromes.end()) {
                int m = min(notPalindromes[it.first], notPalindromes[rev]);
                length += 4 * m;
                notPalindromes[it.first] -= m;
                notPalindromes[rev] -= m;
            }
        }
        debug(length);
        return length + getFromPalindromes(Palindromes);
    }

    int getFromPalindromes(map<string, int>& Palindromes) {
        vector<int> even, odd;
        int count = 0;
        for (auto &e : Palindromes) {
            if (e.second % 2) odd.push_back(e.second);
            else count += (2 * e.second);
        }
        sort(odd.begin(), odd.end());
        debug(odd);
        if (odd.empty() == false) {
            count += (2 * odd.back());
            odd.pop_back();
        }
        int sub = accumulate(odd.begin(), odd.end(), 0);
        sub *= 2;
        sub -= (odd.size() * 2);
        count += sub;
        return count;
    }
};