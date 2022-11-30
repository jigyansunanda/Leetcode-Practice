class OrderedStream {
public:
    vector<string> v;
    int ptr;

    OrderedStream(int n) {
        v.resize(n + 1);
        ptr = 1;
    }

    vector<string> insert(int idKey, string value) {
        v[idKey] = value;
        vector<string> ans;
        while (ptr < (int) v.size() and v[ptr].empty() == false) {
            ans.push_back(v[ptr]);
            ++ptr;
        }
        return ans;
    }
};