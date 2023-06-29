class MyHashMap {
public:
    int M[1000001] = {};
    
    MyHashMap() {
        memset(M, -1, sizeof(M));
    }
    
    void put(int key, int value) {
        M[key] = value;
    }
    
    int get(int key) {
        return M[key];
    }
    
    void remove(int key) {
        M[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */