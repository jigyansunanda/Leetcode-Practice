#include <bits/stdc++.h>
using namespace::std;

#ifdef LOCAL_MACHINE
#include "leetcode.h"
#endif

/* ------------------------------------- Debugger ------------------------------------------ */
template<typename A, typename B> std::ostream& operator<<(std::ostream &os, const std::pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template < typename T_container, typename T = typename std::enable_if < !std::is_same<T_container, std::string>::value, typename T_container::value_type >::type > std::ostream & operator<<(std::ostream &os, const T_container &v) { os << '{'; std::string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void debug() { std::cout << '\n'; }
template<typename Head, typename... Tail> void debug(Head H, Tail... T) { std::cout << ' ' << H; debug(T...); }
// void print(ListNode* head) {while (head) {cout << head->val << ' '; head = head->next;} cout << '\n';}

#ifdef LOCAL_MACHINE
#define debug(...) std::cout << "(" << #__VA_ARGS__ << "):", debug(__VA_ARGS__)
#else
#define debug(...) 42
#define print(...) 42
#endif
/* ----------------------------------------------------------------------------------------- */

class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
};

#ifdef LOCAL_MACHINE
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
}
#endif