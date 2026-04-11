class LRUCache {
public:
    unordered_map<int, int> cache;
    deque<int> lru;
    int cap;
    LRUCache(int capacity) {
        this->cap = capacity;
    }

    void normalize(int key) {
        stack<int> st;
        int val = -1;
        while(true) {
            val = lru.front();
            if(val != key)
                st.push(lru.front());
            
            lru.pop_front();
            if(key == val)  break;
        }

        while(!st.empty()) {
            lru.push_front(st.top());
            st.pop();
        }
        lru.push_front(val);
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end())
            return -1;
        
        normalize(key);

        return cache[key];
    }
    
    void put(int key, int value) {
        if(cache.find(key) == cache.end())
            lru.push_front(key);
        
        cache[key] = value;
        if(lru.size() > cap){
            int dumpKey = lru.back();
            lru.pop_back();
            cache.erase(dumpKey);
        }

        normalize(key);
    }
};
