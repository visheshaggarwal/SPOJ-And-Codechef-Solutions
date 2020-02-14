class LRUCache {
    unordered_map<int,int> m;
    int size;
    list<int> l;
public:
    LRUCache(int capacity) {
        size = capacity;
    }

    int get(int key) {
        if(m.find(key)==m.end())
            return -1;
        else{
            l.remove(key);
            l.push_back(key);
            return m[key];

        }
    }

    void put(int key, int value) {
        if(size>m.size())
        {
            if(m.find(key)!=m.end())
                l.remove(key);
            m[key]=value;
            l.push_back(key);
        }
        else
        {
            if(m.find(key)!=m.end())
                l.remove(key);
            else{
                int a = l.front();
                m.erase(a);
                l.pop_front();
            }
            m[key] = value;
            l.push_back(key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
