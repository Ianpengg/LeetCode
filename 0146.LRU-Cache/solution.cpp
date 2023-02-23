

//



class LRUCache {
 
  list<pair<int, int>> List; // STL implement of double linked list
  unordered_map<int, list<pair<int, int>>::iterator> hash_list;
  int cap;

public:
    LRUCache(int capacity) {
        cap = capacity;
        List.clear();
        hash_list.clear();
    }
    
    int get(int key) {
      if (hash_list.find(key) == hash_list.end()) return -1; //key is not found
      // we need to know current key position
      auto iter = hash_list.find(key); 
      // make the finded node changed with head node;
      List.splice(List.begin(), List, iter->second);
      // Update 
      hash_list[key] = List.begin();

      return hash_list[key]->second;
    }
    
    void put(int key, int value) {
      auto iter = hash_list.find(key);
      if (iter != hash_list.end()) { // if the key is found
        //update the value
        iter->second->second = value;

        List.splice(List.begin(), List, iter->second);
      }
      else { //key is not found
        if (List.size() == cap) {
          // if cache is full
          // delete the last node ( which is not used for most time)
          hash_list.erase(List.back().first);
          List.pop_back();
          // turn the new pushed pair to the head node
          List.push_front(pair<int, int>(key, value));
        } else {
          // turn the new pushed pair to the head node
          List.push_front(pair<int, int>(key, value));
        }
      }
      // Update the hash table
      hash_list[key] = List.begin();
    }
};