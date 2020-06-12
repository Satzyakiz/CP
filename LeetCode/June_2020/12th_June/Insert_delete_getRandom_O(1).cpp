// Design a data structure that supports all following
// operations in average O(1) time.
//
// insert(val): Inserts an item val to the set if not already present.
// remove(val): Removes an item val from the set if present.
// getRandom: Returns a random element from current set of elements.
// Each element must have the same probability of being returned.

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_set<int> us;
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not
    already contain the specified element. */
    bool insert(int val) {
        if(us.find(val) != us.end())
            return false;
        us.insert(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set
    contained the specified element. */
    bool remove(int val) {
        if(us.find(val) == us.end())
            return false;
        us.erase(us.find(val));
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int s = us.size();
        int index = rand() % s;
        auto it = us.begin();
        for(int i=0; i<index; i++)
            it++;
        return *it;
    }
};
