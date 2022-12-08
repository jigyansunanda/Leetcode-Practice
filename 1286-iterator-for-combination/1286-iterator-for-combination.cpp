class CombinationIterator {
public:
    vector<string> v;

    CombinationIterator(string characters, int combinationLength) {
        int n = characters.size();
        int mask = (1 << n);
        for (int i = 0; i < mask; ++i) {
            if (__builtin_popcount(i) == combinationLength) {
                string tmp = "";
                for (int j = 0; j <= n - 1; ++j) {
                    if (i & (1 << (n - 1 - j))) {
                        tmp.push_back(characters[j]);
                    }
                }
                v.push_back(tmp);
            }
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
    }

    string next() {
        string ans = v.back();
        v.pop_back();
        return ans;
    }

    bool hasNext() {
        return (v.empty() == false);
    }
};
/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */