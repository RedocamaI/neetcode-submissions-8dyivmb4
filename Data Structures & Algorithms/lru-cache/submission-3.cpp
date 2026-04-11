class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int value) {
        val = value;
        next = nullptr;
    }
};

class LRUCache {
public:
    unordered_map<int, int> cache;
    ListNode* lru = new ListNode(0);
    ListNode* tail = nullptr;
    int cap;
    int length = 0;
    LRUCache(int capacity) {
        this->cap = capacity;
    }

    void normalize(int key) {
        if(lru->val == key) return;

        ListNode* node = tail;
        if(node->val == key) {
            tail = tail->next;
            node->next = NULL;
            lru->next = node;
            lru = lru->next;

            return;
        }
        
        ListNode* prev = node;
        node = node->next;
        while(node) {
            if(node->val == key)
                break;
            
            prev = node;
            node = node->next;
        }

        prev->next = node->next;
        node->next = NULL;
        lru->next = node;
        lru = lru->next;
    }

    void push_front(int key) {
        ListNode* node = new ListNode(key);
        lru->next = node;
        lru = lru->next;

        length++;
        if(tail == NULL)
            tail = node;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end())
            return -1;
        
        normalize(key);

        return cache[key];
    }
    
    void put(int key, int value) {
        if(cache.find(key) == cache.end())
            push_front(key);
        
        cache[key] = value;
        if(length > cap){
            ListNode* dumpNode = tail;
            int dumpKey = dumpNode->val;

            cache.erase(dumpKey);
            tail = tail->next;
            dumpNode->next = NULL;
            length--;
        }

        normalize(key);
    }
};
