class MyHashSet {
public:
    vector<int> hashSet;
    MyHashSet() {
        hashSet.resize(1000001);
    }
    
    void add(int key) {
        hashSet[key] = 1;
    }
    
    void remove(int key) {
        if(hashSet[key] > 0)
            hashSet[key]--;
    }
    
    bool contains(int key) {
        return hashSet[key] > 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */