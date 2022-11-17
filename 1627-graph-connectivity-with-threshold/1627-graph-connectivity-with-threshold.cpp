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

struct DSU {
public:
    int components;
    vector<int> Parent, Rank;

    DSU(int n) : components(n), Parent(n), Rank(n, 1) { iota(Parent.begin(), Parent.end(), 0); }

    int find(int x) {
        while (x != Parent[x]) x = Parent[x] = Parent[Parent[x]];
        return x;
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (Rank[x] > Rank[y]) swap(x, y);
        Parent[x] = y;
        Rank[y] += Rank[x];
        --components;
        return true;
    }
};

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        DSU dsu(n + 1);
        for (int div = threshold + 1; div <= n; ++div) {
            int a = div;
            for (int b = div * 2; b <= n; b += div) {
                dsu.merge(a, b);
            }
        }
        vector<bool> ans;
        for (auto &q : queries) {
            if (dsu.find(q[0]) == dsu.find(q[1])) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};

#ifdef LOCAL_MACHINE
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
}
#endif