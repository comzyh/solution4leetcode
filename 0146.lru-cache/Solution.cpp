#include <unordered_map>
#include <list>
#include <utility>
using namespace std;
class LRUCache {
public:
    LRUCache(int capacity):capacity(capacity) {
        
    }
    
    int get(int key) {
        auto it = keys.find(key);
        if (it == keys.end()) {
            return -1;
        }
        values.splice(values.begin(), values, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
       auto it = keys.find(key);
       if (it != keys.end()) {
           it->second->second = value;
           values.splice(values.begin(), values, it->second);
           return;
       }
       values.push_front(make_pair(key, value));
       keys.insert(make_pair(key, values.begin()));
       if (keys.size() > capacity) {
           keys.erase(values.rbegin()->first);
           values.pop_back();
       }
    }
private:
    unordered_map<int, list<pair<int, int> >::iterator> keys;
    list<pair<int, int> > values;
    int capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
