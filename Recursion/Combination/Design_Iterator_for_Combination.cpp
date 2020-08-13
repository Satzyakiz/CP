// Design an Iterator class, which has:
//
// A constructor that takes a string characters of sorted distinct
// lowercase English letters and a number combinationLength as arguments.
// A function next() that returns the next combination of length
// combinationLength in lexicographical order.
// A function hasNext() that returns True if and only if there exists a
// next combination.
//
//
// Example:
//
// CombinationIterator iterator = new CombinationIterator("abc", 2);
// // creates the iterator.
//
// iterator.next(); // returns "ab"
// iterator.hasNext(); // returns true
// iterator.next(); // returns "ac"
// iterator.hasNext(); // returns true
// iterator.next(); // returns "bc"
// iterator.hasNext(); // returns false

class CombinationIterator {
public:
    int i;
    vector<string> combinations;
    CombinationIterator(string characters, int combinationLength) {
        i = 0;
        makeCombinations(characters,"",0,combinationLength);
    }
    void makeCombinations(string chars, string temp, int index, int size){
        if(size == 0){
            combinations.emplace_back(temp);
            return;
        }
        if(index >= chars.size()){
            return;
        }
        for(int i=index; i<chars.size(); i++){
            temp.push_back(chars[i]);
            makeCombinations(chars,temp, i+1, size-1);
            temp.pop_back();
        }
    }
    string next() {
        return combinations[i++];
    }

    bool hasNext() {
        if(i < combinations.size()){
            return true;
        }
        return false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
