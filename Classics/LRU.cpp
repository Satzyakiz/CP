// Design and implement a data structure for Least Recently
// Used (LRU) cache. It should support the following operations:
// get and put.
//
// get(key) - Get the value (will always be positive) of the key
// if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not
// already present. When the cache reached its capacity, it should
// invalidate the least recently used item before inserting a new item.
//
// The cache is initialized with a positive capacity.
// Input:
// 2
// 2
// 2
// SET 1 2 GET 1
// 2
// 7
// SET 1 2 SET 2 3 SET 1 5 SET 4 5 SET 6 7 GET 4 GET 1
// Output:
// 2
// 5 -1

//class
class LRU{
public:
  int capacity;
  list<pair<int,int>> l;
  unordered_map<int,list<pair<int,int>>::iterator> um;
  //map of int -> location of a list which contains pairs of int
  LRU(int cap){
    capacity = cap;
  }
  //retrieve value of key
  int get(int key) {
    auto itr = um.find(key); //if key already present, its location would be sent.
    int val = -1; //if key not there, -1 would be returned.
    if(itr != um.end()){ // value found in map
      val = itr->second->second;
      l.erase(itr->second); //The already existing entry is deleted
      um[key] = l.insert(l.begin(),{key,val}); //As it is recently used,
      // it is being placed at first
    }
    //LOGIC:
    // If a key is already there in the map, it is deleted from its
    // existing location and placed at first, as it is the recently Used
    // element
    return val;
  }
  //insert value at a particular key
  void put(int key, int value) {
    auto itr = um.find(key);
    if(itr != um.end()){
      l.erase(itr->second);
    }
    else if(l.size() == capacity){
      um.erase(l.back().first); //The last item is deleted first from map
      l.pop_back(); //Then it is removed from list
    }
    um[key] = l.insert(l.begin(),{key,value});
    //whatever might be the case, the value should be inserted at
    // the beginning as it is the recently used item
  }
  //LOGIC:
  // Insert new value if the key is already existing, else erase the
  // last element and insert the new element in the beginning

};
