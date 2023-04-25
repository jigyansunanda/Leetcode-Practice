class SmallestInfiniteSet {
public:
    set<int> removed;
    
    SmallestInfiniteSet() {}
    
    int popSmallest() {
        for (int i=1; i<=2003; ++i) {
            if (removed.find(i) == removed.end()) {
                removed.insert(i);
                return i;
            }
        }
        return 2004;
    }
    
    void addBack(int num) {
        if (removed.find(num) != removed.end()) {
            auto it = removed.find(num);
            removed.erase(it);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */