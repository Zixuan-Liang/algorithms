class Bucket {
    
    vector<pair<int, int>> bucket;
    
public:
    
    Bucket() {}
    
    int get(int key) {
        for (auto [k, v] : bucket) {
            if (key == k)
                return v;
        }
        return -1;
    }
    
    void update(int key, int value) {
        bool found = false;
        for (int i = 0; i < bucket.size(); i++) {
            if (key == bucket[i].first) {
                bucket[i].second = value;
                found = true;
            }
        }
        if (!found)
            bucket.push_back({key, value});
    }
    
    void remove(int key) {
        for (int i = 0; i < bucket.size(); i++) {
            if (key == bucket[i].first) {
                bucket.erase(bucket.begin() + i);
                break;
            }
        }
    }
};


class MyHashMap {
    
    int keySpace;
    vector<Bucket> hashTable;
    
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        keySpace = 2069;
        hashTable.resize(keySpace, Bucket());
    }
    
    int hash(int key) {
        return key % keySpace;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        hashTable[hash(key)].update(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return hashTable[hash(key)].get(key);
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        hashTable[hash(key)].remove(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */