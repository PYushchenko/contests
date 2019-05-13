class LRUCache {
public:
    list<pair<int,int>> l;
    map<int, list<pair<int,int>>::iterator> m;
    int list_size = 0;
    int max_size;
    LRUCache(int capacity) {
        max_size = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if (it != m.end()) {
            l.splice(l.begin(), l, it->second);
            return it->second->second;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if (it != m.end()) {
            l.erase(it->second);
            list_size--;
            m.erase(it);
        }
        l.push_front({key, value});
        list_size++;
        m[key] = l.begin();
        while (list_size > max_size) {
            auto last = l.end();
            last--;
            m.erase(last->first);
            l.pop_back();
            list_size--;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
