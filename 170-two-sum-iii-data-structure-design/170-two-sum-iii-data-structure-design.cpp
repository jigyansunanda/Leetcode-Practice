class TwoSum {
public:
    unordered_map<long long, int> mp;
    TwoSum() {}
    
    void add(int number) {
        mp[number]++;
    }
    
    bool find(int value) {
        long long val = (long long)value;
        for (auto &e: mp) {
            long long num = e.first;
            int count = e.second;
            long long compliment = value - num;
            if (compliment != num) {
                if (mp.count(compliment)) return true;
            }else {
                if (count > 1) return true;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */