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
    using pii = pair<int, int>;

    vector<int> topStudents(vector<string>& P, vector<string>& N, vector<string>& report, vector<int>& ID, int k) {
        auto comp = [&](const auto & A, const auto & B) {
            if (A.first != B.first) return A.first < B.first;
            else return A.second > B.second;
        };
        priority_queue<pii, vector<pii>, decltype(comp)> pq(comp);
        unordered_set<string> PF(P.begin(), P.end());
        unordered_set<string> NF(N.begin(), N.end());
        for (int i = 0; i < ID.size(); ++i) {
            int id = ID[i];
            int points = 0;
            auto v = get(report[i]);
            debug(v);
            for (auto &s : v) {
                if (PF.find(s) != PF.end()) points += 3;
                if (NF.find(s) != NF.end()) points -= 1;
            }
            pq.push({points, id});
        }
        vector<int> ans;
        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }

    vector<string> get(string s) {
        string a = "";
        vector<string > v;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                v.push_back(a);
                a = "";
            } else a.push_back(s[i]);
        }
        v.push_back(a);
        return v;
    }
};